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

  // Equality u == v
  bool operator==(const Vector3 &other) const;

  // Inequality u != v
  bool operator!=(const Vector3 &other) const;

  // Scalar Multiplication v * s (s * v does not work as a member function) -> defined as free function
  Vector3 operator*(const float s) const;

  static  Vector3 Cross(const Vector3 &u, const Vector3 &v);
  Vector3 operator/(const float s) const;
  // Make vector negative
  Vector3 operator-() const;
  // Vector subtraction
  Vector3 operator-(const Vector3 &other) const;

  // Function operations
  float Dot(const Vector3 &other) const;
  float Magnitude() const;

  // Helper functions
  float LengthSquared() const;

};

// Dot Product as a free function
float operator*(const Vector3 &u, const Vector3 &v);


// Commuative operator overloads
Vector3 operator*(float s,  const Vector3 &v);

// Non-member helper Function
float LengthSquared(const Vector3& u);

} // namespace amumath

#endif // !VECTOR3_H
