#include <gtest/gtest.h>
#include "amumath/Vector3.h"

// Test Fixture: Clean way to organize tests
class Vector3Test : public ::testing::Test {
protected:
    amumath::Vector3 v1 {1.0f, 2.0f, 3.0f};
    amumath::Vector3 v2 {4.0f, 5.0f, 6.0f};
};

TEST_F(Vector3Test, HandlesAddition) {
    amumath::Vector3 result = v1 + v2;
    
    EXPECT_EQ(result.x, 5.0f);
    EXPECT_EQ(result.y, 7.0f);
    EXPECT_EQ(result.z, 9.0f);
}
