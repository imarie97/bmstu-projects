//
// Created by user on 3/18/18.
//

#ifndef DIAMONDSQUARE_STDAFX_HPP
#define DIAMONDSQUARE_STDAFX_HPP

//#define GLFW_INCLUDE_GLCOREARB
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtx/transform.hpp>
#include <random>
#include <iostream>

#include "Camera.h"

using namespace std;
extern std::default_random_engine random_gen;
extern std::uniform_real_distribution<float> dist;

#endif // DIAMONDSQUARE_STDAFX_HPP
