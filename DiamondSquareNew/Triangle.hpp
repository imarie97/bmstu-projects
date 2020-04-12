//
// Created by user on 3/18/18.
//

#ifndef DIAMONDSQUARE_TRIANGLE_HPP
#define DIAMONDSQUARE_TRIANGLE_HPP

#include "stdafx.hpp"

class Triangle {
public:
  glm::vec3 a, b, c;
  glm::vec3 color;

public:
  Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c);
  Triangle();

  void setWater();
  void setBeach();
  void setForest();
  void setMountain();
  void setGlacier();

  glm::vec3 getNormal();
  void recalcColor();
};

#endif // DIAMONDSQUARE_TRIANGLE_HPP
