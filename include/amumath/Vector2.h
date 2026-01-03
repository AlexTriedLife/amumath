#ifndef VECTOR2_H
#define VECTOR2_H
#include <cmath>

namespace amumath {
struct Vector2 {
  float x, y;

  // Default construct as zero vector
  Vector2(float x = 0.0f, float y = 0.0f);

  // Operator overloads
  // Vector addition
  Vector2 operator+(const Vector2 &other) const;

  // ToDo: division, cross
  // Equality u == v
  bool operator==(const Vector2 &other) const;

  // Inequality u != v
  bool operator!=(const Vector2 &other) const;

  // Scalar Multiplication s * v
  Vector2 operator*(const float s) const;

  // TODO: scalar division
  // TODO: Cross product <Make a matrix first>
  Vector2 operator/(const float s) const;
  // Make vector negative
  Vector2 operator-() const;
  // Vector subtraction
  Vector2 operator-(const Vector2 &other) const;

  // Function operations
  float dot(const Vector2 &other) const;

};

// Dot Product as a free function
float operator*(const Vector2 &u, const Vector2 &v);

} // namespace amumath

#endif // VECTOR2_H
