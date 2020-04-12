//
// Created by user on 3/29/18.
//

#ifndef DIAMONDSQUARE_SKYBOX_HPP
#define DIAMONDSQUARE_SKYBOX_HPP

#include "stdafx.hpp"

class Skybox {
  int width, height, n;
  unsigned char *textureData;

public:
  Skybox(char const *filename);
  ~Skybox();

  void render();
};


#endif //DIAMONDSQUARE_SKYBOX_HPP
