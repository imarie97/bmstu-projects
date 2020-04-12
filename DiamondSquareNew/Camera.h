//
// Created by user on 3/17/18.
//

#ifndef DIAMONDSQUARE_CAMERA_H
#define DIAMONDSQUARE_CAMERA_H

#include <glm/core/type.hpp>

class Camera {

private:
  GLFWwindow *window;
  glm::vec3 position;
  glm::mat4 perspective;

public:
  float horizontalAngleRad;
  float verticalAngleRad;

public:
  Camera(GLFWwindow *window, glm::mat4 &perspectiveMatrix,
         const glm::vec3 &startPosition, float startHorizontalAngleRad,
         float startVerticalAngleRad);
  void getViewMatrix(float deltaTimeMs, glm::mat4 *pOutViewMatrix, double mouseDeltaX, double mouseDeltaY);
  glm::vec3 getPosition();
  glm::mat4 getPerspectiveMatrix();

  Camera(Camera const &) = delete;
  void operator=(Camera const &x) = delete;
};

#endif // DIAMONDSQUARE_CAMERA_H
