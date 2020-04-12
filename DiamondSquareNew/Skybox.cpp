//
// Created by user on 3/29/18.
//

#include "Skybox.hpp"
#define STBI_NO_GIF 1
#define STB_IMAGE_IMPLEMENTATION 1
#include "stb/stb_image.h"

Skybox::Skybox(char const *filename) {
  textureData = stbi_load(filename, &width, &height, &n, 3);

  if (textureData == nullptr) {
    std::cerr << "load texture skybox failed" << std::endl;
    std::terminate();
  }
}
Skybox::~Skybox() { stbi_image_free(textureData); };

void Skybox::render() {
  glDisable(GL_DEPTH_TEST);
  glColor3f(1.f, 1.f, 1.f);

  glEnable(GL_TEXTURE_2D);

  glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,
               GL_UNSIGNED_BYTE, textureData);

  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

  glBegin(GL_QUADS);
  glTexCoord2f(0.5f, (2.0f / 3.0f));
  glVertex3f(1.0f, 1.0f, -1.0f);

  glTexCoord2f(0.25f, (2.0f / 3.0f));
  glVertex3f(-1.0f, 1.0f, -1.0f);

  glTexCoord2f(0.25f, 1.0f);
  glVertex3f(-1.0f, 1.0f, 1.0f);

  glTexCoord2f(0.5f, 1.0f);
  glVertex3f(1.0f, 1.0f, 1.0f);
  glEnd();

  glBegin(GL_QUADS);
  glTexCoord2f(0.5f, (2.0f / 3.0f));
  glVertex3f(1.0f, 1.0f, -1.0f);

  glTexCoord2f(0.25f, (2.0f / 3.0f));
  glVertex3f(-1.0f, 1.0f, -1.0f);

  glTexCoord2f(0.25f, (1.0f / 3.0f));
  glVertex3f(-1.0f, -1.0f, -1.0f);

  glTexCoord2f(0.5f, (1.0f / 3.0f));
  glVertex3f(1.0f, -1.0f, -1.0f);
  glEnd();

  glBegin(GL_QUADS);
  glTexCoord2f(0.5f, (2.0f / 3.0f));
  glVertex3f(1.0f, 1.0f, -1.0f);

  glTexCoord2f(0.75f, (2.0f / 3.0f));
  glVertex3f(1.0f, 1.0f, 1.0f);

  glTexCoord2f(0.75f, (1.0f / 3.0f));
  glVertex3f(1.0f, -1.0f, 1.0f);

  glTexCoord2f(0.5f, (1.0f / 3.0f));
  glVertex3f(1.0f, -1.0f, -1.0f);
  glEnd();

  glBegin(GL_QUADS);
  glTexCoord2f(0.25f, (2.0f / 3.0f));
  glVertex3f(-1.0f, 1.0f, -1.0f);

  glTexCoord2f(0.0f, (2.0f / 3.0f));
  glVertex3f(-1.0f, 1.0f, 1.0f);

  glTexCoord2f(0.0f, (1.0f / 3.0f));
  glVertex3f(-1.0f, -1.0f, 1.0f);

  glTexCoord2f(0.25f, (1.0f / 3.0f));
  glVertex3f(-1.0f, -1.0f, -1.0f);
  glEnd();

  glBegin(GL_QUADS);
  glTexCoord2f(0.75f, (2.0f / 3.0f));
  glVertex3f(1.0f, 1.0f, 1.0f);

  glTexCoord2f(1.0f, (2.0f / 3.0f));
  glVertex3f(-1.0f, 1.0f, 1.0f);

  glTexCoord2f(1.0f, (1.0f / 3.0f));
  glVertex3f(-1.0f, -1.0f, 1.0f);

  glTexCoord2f(0.75f, (1.0f / 3.0f));
  glVertex3f(1.0f, -1.0f, 1.0f);
  glEnd();

  glBegin(GL_QUADS);
  glTexCoord2f(0.5f, (1.f / 3.f));
  glVertex3f(1.0f, -1.0f, -1.0f);

  glTexCoord2f(0.25f, (1.f / 3.f));
  glVertex3f(-1.0f, -1.0f, -1.0f);

  glTexCoord2f(0.25f, 0.0f);
  glVertex3f(-1.0f, -1.0f, 1.0f);

  glTexCoord2f(0.5f, 0.0f);
  glVertex3f(1.0f, -1.0f, 1.0f);
  glEnd();

  glDisable(GL_TEXTURE_2D);
  glEnable(GL_DEPTH_TEST);
}
