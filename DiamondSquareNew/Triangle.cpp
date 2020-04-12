#include "stdafx.hpp"
//
// Created by user on 3/18/18.
//

#include "Triangle.hpp"

Triangle::Triangle(glm::vec3 a, glm::vec3 b, glm::vec3 c) {
    this->a = a;
    this->b = b;
    this->c = c;
}
Triangle::Triangle() { a = b = c = glm::vec3(0); }

void Triangle::setWater() {
    color = glm::vec3(0.28f + dist(random_gen) * 0.1f,
                      0.48f + dist(random_gen) * 0.1f,
                      0.78f + dist(random_gen) * 0.1f);
}

void Triangle::setBeach() {
    color =
    //      glm::vec3(0.5f + dist(random_gen) * 0.1f, 0.77f + dist(random_gen) * 0.1f,
    //                0.27f + dist(random_gen) * 0.1f);
    glm::vec3(0.15f + dist(random_gen) * 0.1f, 0.24f + dist(random_gen) * 0.1f,
              0.f + dist(random_gen) * 0.1f);
}

void Triangle::setForest() {
    color =
    glm::vec3(0.05f + dist(random_gen) * 0.1f, 0.2f + dist(random_gen) * 0.1f,
              0.f + dist(random_gen) * 0.1f);
}

void Triangle::setMountain() {
    color =
    glm::vec3(0.4f + dist(random_gen) * 0.1f, 0.4f + dist(random_gen) * 0.1f,
              0.4f + dist(random_gen) * 0.1f);
}

void Triangle::setGlacier() {
    color = glm::vec3(0.95f + dist(random_gen) * 0.1f, 0.95f + dist(random_gen) * 0.1f,
                      0.95f + dist(random_gen) * 0.1f);// - dist(random_gen) * 0.1f);
}

glm::vec3 Triangle::getNormal() {
    
    auto dir = glm::cross(b - a, c - a);
    auto norm = glm::normalize(dir);
    return norm;
}

void Triangle::recalcColor() {
    glm::vec3 normal = getNormal();
    const glm::vec3 UP(0.0f, 1.0f, 0.0f);
    color = glm::vec3(std::abs(glm::dot(UP, normal) * 0.5f));
}
