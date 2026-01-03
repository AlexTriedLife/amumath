#include <gtest/gtest.h>
#include "amumath/Vector3.h"

// Test Fixture: Clean way to organize tests
class Vector3Test : public ::testing::Test {
protected:
    amumath::Vector3 v1 {1.0f, 2.0f, 3.0f};
    amumath::Vector3 v2 {4.0f, 5.0f, 6.0f};
};

// Test vector addition +
TEST_F(Vector3Test, HandlesAddition) {
    amumath::Vector3 result = v1 + v2;
    
    EXPECT_EQ(result.x, 5.0f);
    EXPECT_EQ(result.y, 7.0f);
    EXPECT_EQ(result.z, 9.0f);
}

// Test vector equality ==
TEST_F(Vector3Test, HandlesEquality)    {
    amumath::Vector3 almost_eq_vec = {1.0f, 2.1f, 3.1f};
    amumath::Vector3 equal_vec = {1.0f, 2.0f, 3.0f};

    // Test !=
    EXPECT_TRUE(v1 != almost_eq_vec);
    EXPECT_TRUE(v1 != v2);
    EXPECT_FALSE(v1 != equal_vec);

    // Test ==
    EXPECT_TRUE(v1 == equal_vec);
    EXPECT_FALSE(v1 == almost_eq_vec);
    EXPECT_FALSE(v1 == v2);

}
