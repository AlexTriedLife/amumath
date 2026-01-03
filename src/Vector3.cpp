#include "amumath/Vector2.h"
#include <cmath>

namespace amumath {
// 3 arg constructor
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

// Operator overloads
Vector3 Vector3::operator+(const Vector3 &other) const {
  return {x + other.x, y + other.y, z + other.z};
}

bool Vector3::operator==(const Vector3 &other) const {
  // To guarantee float precision
  float epsilon = 1e-6f;
  // Vectors should be practically equal
  return std::abs(x - other.x) < epsilon && std::abs(y - other.y) < epsilon &&
         std::abs(z - other.z) < epsilon;
}

bool Vector3::operator!=(const Vector3 &other) const {
  return !(*this == other);
}

Vector3 Vector3::operator-() const { return {-x, -y, -z}; }

Vector3 Vector3::operator-(const Vector3 &other) const {
  return {x - other.x, y - other.y, z - other.z};
}

Vector3 Vector3::operator*(const float s) const {
  return {x * s, y * s, z * s};
}

float operator*(const Vector3 &u, const Vector3 &v) { return u.dot(v); }

float Vector3::dot(const Vector3 &other) const {
  return (x * other.x) + (y * other.y) + (z * other.z);
}

} // namespace amumath
