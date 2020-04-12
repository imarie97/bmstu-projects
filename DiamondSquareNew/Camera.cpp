#include "stdafx.hpp"
//
// Created by user on 3/17/18.
//

#include <glm/gtc/matrix_transform.hpp>
#include "Camera.h"

static const float speed = 150.0f; // units per second
static const float mouseSpeedRad = 0.0005f;

Camera::Camera(GLFWwindow *window, glm::mat4& perspectiveMatrix, const glm::vec3 &startPosition,
               float startHorizontalAngleRad, float startVerticalAngleRad)
    : window(window), position(startPosition),
      horizontalAngleRad(startHorizontalAngleRad),
      verticalAngleRad(startVerticalAngleRad), perspective(perspectiveMatrix) {}

void Camera::getViewMatrix(float deltaTimeMs, glm::mat4 *pOutViewMatrix, double mouseDeltaX, double mouseDeltaY) {
  float deltaTimeSec = deltaTimeMs / 1000.0f;

  int windowWidth, windowHeight;
  glfwGetWindowSize(window, &windowWidth, &windowHeight);

  horizontalAngleRad += mouseSpeedRad * mouseDeltaX;//(windowWidth / 2 - mouseX);
  verticalAngleRad += mouseSpeedRad * mouseDeltaY;//(windowHeight / 2 - mouseY);


  glm::vec3 direction(cos(verticalAngleRad) * sin(horizontalAngleRad),
                      sin(verticalAngleRad),
                      cos(verticalAngleRad) * cos(horizontalAngleRad));

  glm::vec3 right = glm::vec3(sin(horizontalAngleRad - 3.14f / 2.0f), 0,
                              cos(horizontalAngleRad - 3.14f / 2.0f));

  glm::vec3 up = glm::cross(right, direction);

  if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS) {
    position += direction * deltaTimeSec * speed;
  }

  if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS) {
    position -= direction * deltaTimeSec * speed;
  }

  if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS) {
    position -= right * deltaTimeSec * speed;
  }

  if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS) {
    position += right * deltaTimeSec * speed;
  }

  *pOutViewMatrix = glm::lookAt(position, position + direction, up);
}

glm::vec3 Camera::getPosition() {
  return position;
}

glm::mat4 Camera::getPerspectiveMatrix() {
  return perspective;
};
