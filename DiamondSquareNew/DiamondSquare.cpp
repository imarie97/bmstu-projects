#include "stdafx.hpp"
//
// Created by user on 3/18/18.
//

#include "DiamondSquare.hpp"

// Алгоритм diamond-square начинает работу с двумерного массива размера 2^n + 1.
// В четырех угловых точках массива устанавливаются начальные значения высот.
// Шаги diamond и square выполняются поочередно до тех пор,
// пока все значения массива не будут установлены.
std::vector<std::vector<float>> DiamondSquare::getHeightmap(float seed) {
  // Карта высот
  std::vector<std::vector<float>> m(this->size, std::vector<float>(this->size, 0.0f));

  // Инициализация угловых точек.
  // Присваивание им значений высот (выбором случайных чисел).
  m[0][0] = (dist(random_gen) * seed);
  m[m.size() - 1][0] = (dist(random_gen) * seed);
  m[0][m.size() - 1] = (dist(random_gen) * seed);
  m[m.size() - 1][m.size() - 1] = (dist(random_gen) * seed);

  // Шаги diamond и square выполняются поочередно
  // до тех пор, пока все значения массива не будут установлены.

  int step = m.size() - 1;
  // Случайное значение, прибавляющееся к срединным точкам
  float stepRangeRandomValue = this->range;
  while (step > 1) {

    // Шаг square (квадрат).
    // Для каждого квадрата в массиве,
    // находится срединная точка, в которую устанавливается
    // среднее значение четырех угловых точек плюс случайное значение.

    for (size_t x = 0; x < m.size() - 1; x += step) {
      for (size_t y = 0; y < m.size() - 1; y += step) {
        size_t sx = x + (step >> 1);
        size_t sy = y + (step >> 1);

        // Нахождение срединной точки, присваивание ей значения,
        // на основе среднего от угловых, плюс случайное число.
        m[sx][sy] = (m[x][y] + m[x + step][y] + m[x][y + step] +
                     m[x + step][y + step]) /
                    4.0f;
        m[sx][sy] += (dist(random_gen) * stepRangeRandomValue -
                      stepRangeRandomValue / 2.0f);
      }
    }

    // Шаг diamond (ромб).
    // Для каждого ромба в массиве, устанавливается
    // срединная точка, которой присваивается среднее
    // арифметическое из четырех угловых точек
    // плюс случайное значение.

    for (size_t x = 0; x < m.size() - 1; x += step) {
      for (size_t y = 0; y < m.size() - 1; y += step) {
        int halfstep = step >> 1;
        // Квадрат
        int x1 = x + halfstep;
        int y1 = y;
        int x2 = x;
        int y2 = y + halfstep;

        // Нахождение значения высот срединных точек для ромбов.
        auto calcHeight = [&m, &stepRangeRandomValue](int x, int y,
                                                      int halfstep) -> float {
          std::vector<float> diamondPoints;

          if (x - halfstep > 0)
            diamondPoints.push_back(m[x - halfstep][y]);
          if (y - halfstep > 0)
            diamondPoints.push_back(m[x][y - halfstep]);
          if (x + halfstep < m.size())
            diamondPoints.push_back(m[x + halfstep][y]);
          if (y + halfstep < m.size())
            diamondPoints.push_back(m[x][y + halfstep]);

          // Cреднеe значение высот, плюс случайное число
          return std::accumulate(diamondPoints.begin(), diamondPoints.end(),
                                 0.0f) /
                     diamondPoints.size() +
                 (dist(random_gen) * stepRangeRandomValue -
                  stepRangeRandomValue / 2.0f);
        };

        m[x1][y1] = calcHeight(x1, y1, halfstep);
        m[x2][y2] = calcHeight(x2, y2, halfstep);
      }
    }
    // На каждой итерации случайное значение,
    // прибавляющееся к срединным точкам, уменьшается.
    stepRangeRandomValue /= divisor;
    step >>= 1;
  }

  // Шаг smooth (сглаживание)
  if (smoothLevel != SmoothLevel::OFF) {
    smoothStep(m, this->smoothLevel);
  }

  return m;
}

void DiamondSquare::smoothStep(std::vector<std::vector<float>> &heightmap,
                               SmoothLevel smoothLevel) {
  // Получение среднего значения точек по уровню сглаживания
  auto neighbours_avg = [&smoothLevel, &heightmap](size_t x, size_t y) {
    switch (smoothLevel) {
    case SmoothLevel::MEDIUM:
      // Среднее значение 4 соседних точек
      return (heightmap[x - 1][y] + heightmap[x][y - 1] + heightmap[x + 1][y] +
              heightmap[x][y + 1]) /
             4.0f;

    case SmoothLevel::HARD:
      // Среднее значение 8 соседних точек
      return (heightmap[x - 1][y] + heightmap[x][y - 1] + heightmap[x + 1][y] +
              heightmap[x][y + 1] + heightmap[x - 1][y - 1] +
              heightmap[x - 1][y - 1] + heightmap[x + 1][y + 1] +
              heightmap[x + 1][y + 1]) /
             8.0f;
    }
  };

  for (size_t i = 1; i < heightmap.size() - 1; i++) {
    for (size_t j = 1; j < heightmap.size() - 1; j++) {
      heightmap[i][j] = neighbours_avg(i, j);
    }
  }
}

DiamondSquare::DiamondSquare(size_t size, float range, float divisor,
                             SmoothLevel smoothLevel) {
  this->range = range;
  this->divisor = divisor;
  this->smoothLevel = smoothLevel;
  this->size = size;
}
