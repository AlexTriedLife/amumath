#include "amumath/Vector3.h"
#include <format>

namespace amumath {
// 3 arg constructor
Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

// Operator overloads (member functions)
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

Vector3 Vector3::operator/(const float s) const {
  return {x / s, y / s, z / s};
}

// Member functions
float Vector3::Dot(const Vector3 &other) const {
  return (x * other.x) + (y * other.y) + (z * other.z);
}

Vector3 Vector3::Cross(const Vector3 &u, const Vector3 &v) {
  return {u.y * v.z - u.z * v.y, u.z * v.x - u.x * v.z, u.x * v.y - u.y * v.x};
}

float Vector3::LengthSquared() const { return x * x + y * y + z * z; }

float Vector3::Magnitude() const { return std::sqrt(LengthSquared()); }

void Vector3::Normalize() {
  float len_sq = LengthSquared();
  // Check if sqrt is necessary <practically zero: less than epsilon>
  if (len_sq > 1e-6) {
    // Mult by 1 / magnitude<square root of length squared> so we only call sqrt
    // once
    float iMag = 1.0f / std::sqrt(len_sq);
    x *= iMag;
    y *= iMag;
    z *= iMag;
  } else {
    // Sqrt is not needed so we set the current instance to the zero vector
    *this = Zero();
  }

  // Normalize
}

// Helpers
const Vector3 Vector3::Zero() { return {0.0f, 0.0f, 0.0f}; }

float LengthSquared(const Vector3 &u) {
  return u.x * u.x + u.y * u.y + u.z * u.z;
}

std::string Vector3::ToString() const {
    return std::format("({}, {}, {})", x, y, z);
}

// Free functions
// Commutative operations
float operator*(const Vector3 &u, const Vector3 &v) { return u.Dot(v); }
// Scalar mult s * v
Vector3 operator*(float s, const Vector3 &v) { return v * s; }

} // namespace amumath
