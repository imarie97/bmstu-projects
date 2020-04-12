//
// Created by user on 3/18/18.
//
#include "stdafx.hpp"

#include "Terrain.hpp"
std::vector<Triangle>
Terrain::getTriangles(std::vector<std::vector<float>> &heightmap,
                      float length) {
  int trianglesCount = ((heightmap.size() - 1) * (heightmap[0].size() - 1)) * 2;
  std::vector<Triangle> triangles(trianglesCount, Triangle{});
  for (size_t j = 0; j < heightmap[0].size() - 1; j++) {

    // Карта высот представляет собой сетку - квадраты
    // Для рисования необходимо два треугольника
    for (size_t i = 0; i < heightmap.size() - 1; i++) {
      // Первая половина треугольников
      triangles.emplace_back(
        Triangle(glm::vec3(i * length, heightmap[j][i], j * length),
                 glm::vec3((i + 1) * length, heightmap[j + 1][i + 1],(j + 1) * length),
                 glm::vec3((i + 1) * length, heightmap[j][i + 1], j * length)));

      // Вторая половина треугольников
      triangles.emplace_back(
          Triangle(glm::vec3(i * length, heightmap[j][i], j * length),
                   glm::vec3(i * length, heightmap[j + 1][i], (j + 1) * length),
                   glm::vec3((i + 1) * length, heightmap[j + 1][i + 1],
                             (j + 1) * length)));
    }
  }

  // Цвет треугольника
  for (size_t i = 0; i < triangles.size(); i++) {
    triangles[i].recalcColor();
  }
  return triangles;
}

void Terrain::render() {
  glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);
  glEnable(GL_COLOR_MATERIAL);

  glEnableClientState(GL_VERTEX_ARRAY);
  glEnableClientState(GL_NORMAL_ARRAY);
  glEnableClientState(GL_COLOR_ARRAY);

  glNormalPointer(GL_FLOAT, 0, normalBuffer.data());
  glColorPointer(3, GL_FLOAT, 0, colorBuffer.data());
  glVertexPointer(3, GL_FLOAT, 0, vertexBuffer.data());
  glDrawArrays(GL_TRIANGLES, 0, vertexBuffer.size());

  glDisableClientState(GL_COLOR_ARRAY);
  glDisableClientState(GL_NORMAL_ARRAY);
  glDisableClientState(GL_VERTEX_ARRAY);

  glDisable(GL_COLOR_MATERIAL);
}

Terrain::Terrain(std::vector<std::vector<float>> &heightmap, float length) {
  createFromHeightmap(heightmap, length);
}

void Terrain::setupColorsForTerrain(
    std::unordered_map<SoilType, float, std::hash<int>> &heightLevels) {

  for (size_t i = 0; i < triangles.size(); i++) {
    if (triangles[i].a.y == heightLevels[SoilType::WATER]) {
      triangles[i].setWater();
    }
    if (triangles[i].a.y > heightLevels[SoilType::WATER] &&
        triangles[i].a.y < heightLevels[SoilType::STEPPE]) {
      triangles[i].setBeach();
    } else if (triangles[i].a.y < heightLevels[SoilType::WATER]) {
        triangles[i].setMountain();
    } else if (triangles[i].a.y > heightLevels[SoilType::STEPPE] &&
               triangles[i].a.y < heightLevels[SoilType::FOREST]) {
      triangles[i].setForest();
    } else if (triangles[i].a.y > heightLevels[SoilType::FOREST] &&
               triangles[i].a.y < heightLevels[SoilType::MOUNTAIN]) {
      triangles[i].setMountain();
    } else if (triangles[i].a.y > heightLevels[SoilType::MOUNTAIN] &&
               triangles[i].a.y < heightLevels[SoilType::GLACIER]) {
      triangles[i].setGlacier();
    } else {
       triangles[i].setGlacier();
    }
  }
  resetBuffers();
}

void Terrain::createFromHeightmap(std::vector<std::vector<float>> &heightmap,
                                  float length) {
  this->triangles = getTriangles(heightmap, length);
  resetBuffers();
}

void Terrain::resetBuffers() {

  vertexBuffer.clear();
  colorBuffer.clear();
  normalBuffer.clear();

  for (size_t i = 0; i < triangles.size(); i++) {
    vertexBuffer.emplace_back(triangles[i].a);
    vertexBuffer.emplace_back(triangles[i].b);
    vertexBuffer.emplace_back(triangles[i].c);

    colorBuffer.emplace_back(triangles[i].color);
    colorBuffer.emplace_back(triangles[i].color);
    colorBuffer.emplace_back(triangles[i].color);

    normalBuffer.emplace_back(triangles[i].getNormal());
    normalBuffer.emplace_back(triangles[i].getNormal());
    normalBuffer.emplace_back(triangles[i].getNormal());
  }
}
