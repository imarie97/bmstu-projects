#include "Application.hpp"
#include <chrono>

// Управление
// WASD - движение по карте
// M - меню

// Построение ландшафтных изображений на основе использования фрактальных
// структур
// Алгоритм ромб-квадрат (Diamond-square algorithm)
int main() {

  // Инициализация ГСЧ
  random_gen = std::default_random_engine(
      std::chrono::system_clock::now().time_since_epoch().count());

  Application app(1024, 768); //width, height
  //Параметры света
  app.lightPos = glm::vec4(-30.0f, 60.0f, 0.0f, 0.5f);
  app.lightColorAmbient = glm::vec4(0.2f, 0.2f, 0.2f, 1.f);
  app.lightColorSpecular = glm::vec4(0.5f, 0.5f, 0.5f, 0.5f);
  app.lightColorDiffuse = glm::vec4(0.5f, 0.5f, 0.5f, 0.5f);
  app.waterColor = glm::vec4(0.28f, 0.48f, 0.8f, 0.6f);

  app.setCursorShow(false);
  // Запуск бесконченого цикла отрисовки
  app.runRenderLoop();

  return 0;
}
