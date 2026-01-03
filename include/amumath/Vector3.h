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

  // ToDo: Scalar mult, subtraction, equality, division, dot product, cross
  // product, etc.
  Vector3 operator==(const Vector3 &other) const;
};
} // namespace amumath

#endif // !VECTOR3_H
