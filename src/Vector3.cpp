#include "amumath/Vector3.h"

namespace amumath {
    // 3 arg constructor
    Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {}

    // Operator overloads
    Vector3 Vector3::operator+(const Vector3& other) const {
        return Vector3(x + other.x, y + other.y, z + other.z);
    }
    
}
