#include "amumath/Vector2.h"
#include <cmath>

namespace amumath {
// 3 arg constructor
Vector2::Vector2(float x, float y) : x(x), y(y) {}

// Operator overloads
Vector2 Vector2::operator+(const Vector2 &other) const {
  return {x + other.x, y + other.y};
}

bool Vector2::operator==(const Vector2 &other) const {
  // To guarantee float precision
  float epsilon = 1e-6f;
  // Vectors should be practically equal
  return std::abs(x - other.x) < epsilon && std::abs(y - other.y) < epsilon;
}

bool Vector2::operator!=(const Vector2 &other) const {
  return !(*this == other);
}

Vector2 Vector2::operator-() const { return {-x, -y}; }

Vector2 Vector2::operator-(const Vector2 &other) const {
  return {x - other.x, y - other.y};
}

Vector2 Vector2::operator*(const float s) const {
  return {x * s, y * s};
}

float operator*(const Vector2 &u, const Vector2 &v) { return u.dot(v); }

float Vector2::dot(const Vector2 &other) const {
  return (x * other.x) + (y * other.y);
}

} // namespace amumath

