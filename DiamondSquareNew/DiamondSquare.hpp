//
// Created by user on 3/18/18.
//

#ifndef DIAMONDSQUARE_DIAMONDSQUARE_HPP
#define DIAMONDSQUARE_DIAMONDSQUARE_HPP

#include "stdafx.hpp"

enum SmoothLevel { OFF, MEDIUM, HARD };

// Построение ландшафтных изображений на основе использования фрактальных
// структур
// Алгоритм ромб-квадрат (Diamond-square algorithm)

// Алгоритм Diamond-Square — метод генерации карт высот для компьютерной
// графики.
// Алгоритм начинает работу с 2D сетки, затем, из четырех начальных значений,
// случайным образом генерирует карту высот, упорядоченную в виде сетки из точек
// так, чтобы вся плоскость была покрыта квадратами.
class DiamondSquare {

private:
  size_t size;
  float range;
  float divisor;
  SmoothLevel smoothLevel;

public:
  DiamondSquare(size_t size, float range, float divisor,
                SmoothLevel smoothLevel);

  // Генерация карты высот
  std::vector<std::vector<float>> getHeightmap(float seed);

private:
  // Сглаживание карты высот
  void smoothStep(std::vector<std::vector<float>> &heightmap, SmoothLevel smoothLevel);
};

#endif // DIAMONDSQUARE_DIAMONDSQUARE_HPP
