//
// Created by user on 3/18/18.
//

#ifndef DIAMONDSQUARE_MESH_HPP
#define DIAMONDSQUARE_MESH_HPP

#include "Triangle.hpp"
#include <unordered_map>
#include <vector>

enum SoilType { WATER, STEPPE, FOREST, MOUNTAIN, GLACIER };

class Terrain {
public:
  std::vector<Triangle> triangles;
  std::vector<glm::vec3> vertexBuffer;
  std::vector<glm::vec3> colorBuffer;
  std::vector<glm::vec3> normalBuffer;

private:
  std::vector<Triangle> getTriangles(std::vector<std::vector<float>> &heightmap,
                                     float length);

  void createFromHeightmap(std::vector<std::vector<float>> &heightmap,
                           float length);

public:
  Terrain(std::vector<std::vector<float>> &heightmap, float length);

  void resetBuffers();

  // Устанавливает цвета для треугольников ландшафта
  void setupColorsForTerrain(
      std::unordered_map<SoilType, float, std::hash<int>> &heightLevels);

  void render();
};

#endif // DIAMONDSQUARE_MESH_HPP
