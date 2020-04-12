#include "stdafx.hpp"
//
// Created by user on 3/18/18.
//

#include "Application.hpp"
#include "DiamondSquare.hpp"
#include "imgui.h"
#include "imgui_impl_glfw_gl2.h"
#include <algorithm>
#include <chrono>

void error_callback(int error, const char *desc) {
  std::cerr << "Error: " << desc << std::endl;
}

void window_size_callback(GLFWwindow* window, int width, int height)
{
  glViewport(0, 0, width, height);
}

Application::Application(int window_width, int window_height) {
  this->window_width = window_width;
  this->window_height = window_height;
  wireframeRender = false;
  lightEnabled = true;

  glfwSetErrorCallback(error_callback);

  if (!glfwInit()) {
    std::cerr << "Failed to initialize GLFW" << std::endl;
    std::terminate();
  }

  glfwDefaultWindowHints();


  window = glfwCreateWindow(window_width, window_height,
                            "Diamond-square algorithm", nullptr, nullptr);
  if (window == nullptr) {
    std::cerr << "Failed to open GLFW window" << std::endl;
    glfwTerminate();
    std::terminate();
  }

  glm::mat4 projection = glm::perspective(
      80.0f, (float)window_width / window_height, 0.3f, 1700.0f);

  camera = new Camera(window, projection, glm::vec3(0, 0, 0),
                      0.0f /* toward -Z */, 0.0f /* look at the horizon */);

  glfwMakeContextCurrent(window);
  glfwSetWindowSizeCallback(window, window_size_callback);
  // vsync
  glfwSwapInterval(1);

  // Setup ImGui binding
  ImGui::CreateContext();
  ImGuiIO &io = ImGui::GetIO();
  io.ConfigFlags |=
      ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
  ImGui_ImplGlfwGL2_Init(window, true);

  // Setup style
  ImGui::StyleColorsDark();

  // Включение z- (глубинного) буфера для удаления невидимых поверхностей.
  glEnable(GL_DEPTH_TEST);
  glDepthFunc(GL_LEQUAL);

  // Определяем цвет "закраски" буфера.
  glClearColor(0.f, 0.f, 0.f, 1.f);

  glfwSetWindowUserPointer(window, this);
  glfwSetKeyCallback(window, [](GLFWwindow *window, int key, int scancode,
                                int action, int mode) {
    Application *app = (Application *)glfwGetWindowUserPointer(window);
    // Клавиша открытия меню
    if (key == GLFW_KEY_M && action == GLFW_PRESS) {
      app->show_menu = !app->show_menu;
      app->setCursorShow(app->show_menu);
    } 
  });

  // Масштабирование ланшафта
  scaleTerrain = glm::vec3(1.0f);

  // Создние меша (mesh) для для нашего ландшафта (landscape/terrain)
  // diamond_square_parameters
  dsparam.size_N = 8;
  size_t size = (1 << dsparam.size_N) + 1; // 2^n + 1 = 257, n = 8
  dsparam.range = 600.0f;
  dsparam.divisor = 2.0f;
  dsparam.smoothLevel = SmoothLevel::HARD;
  dsparam.seed = 0.0f; //нач высота в углах
  dsparam.waterPercent = 0.3f;
  dsparam.length = 5.0f;

  DiamondSquare diamondSquare(size, dsparam.range, dsparam.divisor,
                              dsparam.smoothLevel);
  // Получение карты высот
  auto heightmap = diamondSquare.getHeightmap(dsparam.seed);
  // Определение уровней высот типов почвы
  auto levels = getHeightLevels(heightmap, dsparam.waterPercent);
  waterLevel = levels[SoilType::WATER];
  terrain = new Terrain(heightmap, dsparam.length);
  terrain->setupColorsForTerrain(levels);
  skybox = new Skybox("./resources/daylight.tga");
   // skybox = new Skybox("./resources/stormydays_large.tga");
    
}

Application::~Application() {
  delete (camera);
  delete (skybox);
  delete (terrain);

  // Cleanup GUI
  ImGui_ImplGlfwGL2_Shutdown();
  ImGui::DestroyContext();

  glfwDestroyWindow(window);
  glfwTerminate();
}

void Application::runRenderLoop() {
  auto startTime = std::chrono::high_resolution_clock::now();
  auto prevTime = startTime;

  glm::mat4 projection;
  glm::mat4 view;

  double prevMouseX, prevMouseY;
  glfwGetCursorPos(window, &prevMouseX, &prevMouseY);

  while (!glfwWindowShouldClose(window)) {

    auto currentTime = std::chrono::high_resolution_clock::now();
    float prevDeltaTimeMs =
        std::chrono::duration_cast<std::chrono::milliseconds>(currentTime -
                                                              prevTime)
            .count();
    prevTime = currentTime;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (wireframeRender) {
      glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    } else {
      glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    }

    double mouseX, mouseY;
    glfwGetCursorPos(window, &mouseX, &mouseY);
    // Настройка матрицы проекции
    projection = camera->getPerspectiveMatrix();
    if (!show_menu) {
      camera->getViewMatrix(prevDeltaTimeMs, &view, prevMouseX - mouseX,
                            prevMouseY - mouseY);
    }
    prevMouseX = mouseX;
    prevMouseY = mouseY;
    glm::mat4 model = glm::mat4(1.0f);
    model = glm::scale(model, scaleTerrain);
    glm::mat4 mvp = projection * view * model;

    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(
        glm::value_ptr(glm::mat4(projection * glm::mat4(glm::mat3(view)) *
                                 glm::scale(glm::vec3(200.f, 200.f, 200.f)))));

    // Отрисовка текстуры неба (skybox)
    skybox->render();

    glLoadMatrixf(glm::value_ptr(mvp));

    // Cвет в OpenGL
    // Установка глобального освещения
    if (lightEnabled) {
      // Установка параметров света
        glEnable(GL_LIGHTING);
        glEnable(GL_LIGHT0);
        glLightfv(GL_LIGHT0, GL_POSITION, glm::value_ptr(lightPos));
        glLightfv(GL_LIGHT0, GL_AMBIENT, glm::value_ptr(lightColorAmbient));
        glLightfv(GL_LIGHT0, GL_DIFFUSE, glm::value_ptr(lightColorDiffuse));
        glLightfv(GL_LIGHT0, GL_SPECULAR, glm::value_ptr(lightColorSpecular));
    }

    // Отрисовка ландшафта
    terrain->render();

    if (lightEnabled) {
      glDisable(GL_LIGHT0);
      glDisable(GL_LIGHTING);
    }

    float s = ((1 << dsparam.size_N) + 1) * dsparam.length;
    renderWater(s);

    // Меню
    if (show_menu) {
      ImGui_ImplGlfwGL2_NewFrame();

      ImGui::Begin("Menu", &show_menu);
      ImGui::SetWindowSize(ImVec2(500.0f, 400.0f));//размер

      // Меню освещения
      if (ImGui::CollapsingHeader("Lighting")) {
        // Свет включен?
        ImGui::Checkbox("Light", &lightEnabled);
        // Позиция света
        ImGui::DragFloat3("Light position", glm::value_ptr(this->lightPos));
        // Интенсивность
        //ImGui::DragFloat("Light intensity", &lightPos.w, 0.01f, 0.0f, 1.0f);
        ImGui::ColorEdit4("Light ambient color",
                          glm::value_ptr(this->lightColorAmbient));
        ImGui::ColorEdit4("Light specular color",
                          glm::value_ptr(this->lightColorSpecular));
        ImGui::ColorEdit4("Light diffuse color",
                          glm::value_ptr(this->lightColorDiffuse));
      }

      ImGui::Spacing();

      // Пункт меню "Вода"
      if (ImGui::CollapsingHeader("Water")) {
        ImGui::ColorEdit4("Water color", glm::value_ptr(this->waterColor));
        ImGui::DragFloat("Waterline", &waterLevel, 1.0f, -100.0f, 100.0f);
      }

      ImGui::Spacing();

      if (ImGui::CollapsingHeader("Terrain")) {
        ImGui::DragFloat3("Terrain scale", glm::value_ptr(scaleTerrain), 0.1f, 0.0f,
                            5.0f);
      }

      ImGui::Spacing();

      // Пункт меню генирации ландшафта
      if (ImGui::CollapsingHeader("Diamond Square")) {
        ImGui::DragInt("Size", (int *)&dsparam.size_N, 1, 1, 8);
        ImGui::DragFloat("Range", &dsparam.range);
        ImGui::DragFloat("Divisor", &dsparam.divisor);
        ImGui::DragFloat("Length", &dsparam.length, 0.1f, 0.1f, 20.0f);

        if (ImGui::Button("Generate")) {
          if (terrain)
            delete terrain;
          size_t size = (1 << dsparam.size_N) + 1; // 2^n + 1
          DiamondSquare diamondSquare(size, dsparam.range, dsparam.divisor,
                                      dsparam.smoothLevel);
          // Получение карты высот
          auto heightmap = diamondSquare.getHeightmap(dsparam.seed);
          // Определение уровней высот типов почвы
          auto levels = getHeightLevels(heightmap, dsparam.waterPercent);
          waterLevel = levels[SoilType::WATER];
          terrain = new Terrain(heightmap, dsparam.length);
          terrain->setupColorsForTerrain(levels);
        }
      }

      ImGui::Spacing();

      ImGui::Checkbox("Wireframe", &wireframeRender);
      ImGui::End();

      ImGui::Render();
      ImGui_ImplGlfwGL2_RenderDrawData(ImGui::GetDrawData());
    }
    glfwPollEvents();
    glfwSwapBuffers(window);
  }
}

std::unordered_map<SoilType, float, std::hash<int>>
getHeightLevels(std::vector<std::vector<float>> &heightmap,
                float waterPercent) {

  assert(waterPercent >= 0.0f && waterPercent <= 1.0f);

  // Находим максимальную точку карты высот
  auto scanHighest = [](std::vector<std::vector<float>> &heightmap) {
    float high = numeric_limits<float>::min();
    for (auto &&row : heightmap) {
      high = max(high, *max_element(row.begin(), row.end()));
    }
    return high;
  };

  // Находим минимальную точку карты высот
  auto scanLowest = [](std::vector<std::vector<float>> &heightmap) {
    float low = numeric_limits<float>::max();
    for (auto &&row : heightmap) {
      low = min(low, *min_element(row.begin(), row.end()));
    }
    return low;
  };

  float low = scanLowest(heightmap);
  float high = scanHighest(heightmap);
  float height = (high - low);

  // Находим уровни высот
  std::unordered_map<SoilType, float, std::hash<int>> heightLevels;
  heightLevels[SoilType::WATER] = low + height * waterPercent;
  heightLevels[SoilType::STEPPE] = heightLevels[SoilType::WATER] + height * 0.1f;
  heightLevels[SoilType::FOREST] =
      heightLevels[SoilType::STEPPE] + height * 0.3f;
  heightLevels[SoilType::MOUNTAIN] =
      heightLevels[SoilType::FOREST] + height * 0.2f;
  heightLevels[SoilType::GLACIER] = high;

  return heightLevels;
}

void Application::renderWater(float s) {

  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  // Цвет воды
  glColor4fv(glm::value_ptr(waterColor));

  glBegin(GL_TRIANGLES);

  glVertex3f(0.0f, waterLevel + 10.0f, 0.0f);
  glVertex3f(s, waterLevel + 10.0f, s);
  glVertex3f(0.0f, waterLevel + 10.0f, s);

  glVertex3f(0.0f, waterLevel + 10.0f, 0.0f);
  glVertex3f(s, waterLevel + 10.0f, 0.0f);
  glVertex3f(s, waterLevel + 10.0f, s);

  glEnd();
  glDisable(GL_BLEND);
}
