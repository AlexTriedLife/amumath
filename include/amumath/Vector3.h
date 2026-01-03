#ifndef VECTOR3_H
#define VECTOR3_H

namespace amumath {
struct Vector3 {
  float x, y, z;

  // Default construct as zero vector
  Vector3(float x = 0.0f, float y = 0.0f, float z = 0.0f);

  // Operator overloads

  // Vector addition
  Vector3 operator+(const Vector3 &other) const;

  // ToDo: division, cross
  // Equality u == v
  bool operator==(const Vector3 &other) const;

  // Inequality u != v
  bool operator!=(const Vector3 &other) const;

  // Scalar Multiplication s * v
  Vector3 operator*(const float s) const;

  // TODO: scalar division
  // TODO: Cross product <Make a matrix first>
  Vector3 operator/(const float s) const;
  // Make vector negative
  Vector3 operator-() const;
  // Vector subtraction
  Vector3 operator-(const Vector3 &other) const;

  // Function operations
  float dot(const Vector3 &other) const;

};

// Dot Product as a free function
float operator*(const Vector3 &u, const Vector3 &v);

} // namespace amumath

#endif // !VECTOR3_H
