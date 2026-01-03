#include "amumath/Vector3.h"
#include <cmath>

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

float Vector3::LengthSquared() const {
    return x * x + y * y + z * z;
}

float Vector3::Magnitude() const {
    return std::sqrt(LengthSquared());
}


// Helpers
float LengthSquared(const Vector3 &u)   {
    return {
        u.x * u.x +
        u.y * u.y +
        u.z * u.z
    };
}

// Free functions
// Commutative operations
float operator*(const Vector3 &u, const Vector3 &v) { return u.Dot(v); }
// Scalar mult s * v
Vector3 operator*(float s, const Vector3 &v) {
    return v * s;
}

} // namespace amumath
