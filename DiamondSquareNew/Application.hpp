//
// Created by user on 3/18/18.
//

#ifndef DIAMONDSQUARE_APP_HPP
#define DIAMONDSQUARE_APP_HPP

#include "Skybox.hpp"
#include "Terrain.hpp"
#include "Triangle.hpp"
#include "stdafx.hpp"
#include "DiamondSquare.hpp"
#include <unordered_map>

std::unordered_map<SoilType, float, std::hash<int>> getHeightLevels(std::vector<std::vector<float>> &heightmap, float waterPercent);

class Application {
private:
  GLFWwindow *window;
  Camera *camera;
  Skybox *skybox;

  int window_width, window_height;
    
  // Меш ландшафта
  Terrain *terrain;
  // Режим рендеринга сеткой
  bool wireframeRender;
  // Свет
  bool lightEnabled;
public:

  struct diamond_square_parameters {
    float range;
    float seed;
    float length;
    float divisor;
    size_t size_N;
    float waterPercent;
    SmoothLevel smoothLevel;
  } dsparam;

  bool show_menu = false;
  //Свет
  glm::vec4 lightPos;
  glm::vec4 lightColorAmbient;
  glm::vec4 lightColorSpecular;
  glm::vec4 lightColorDiffuse;

  // Цвет воды
  glm::vec4 waterColor;
  float waterLevel = 0.0f;

  // Масштабирование ланшафта
  glm::vec3 scaleTerrain;

  Application(int window_width, int window_height);
  ~Application();

  void runRenderLoop();
  void setCursorShow(bool show) {
    int value = show ? GLFW_CURSOR_NORMAL : GLFW_CURSOR_DISABLED;
    glfwSetInputMode(window, GLFW_CURSOR, value);
  }

private:
  // Отрисовка воды
  void renderWater(float s);
};

#endif // DIAMONDSQUARE_APP_HPP
