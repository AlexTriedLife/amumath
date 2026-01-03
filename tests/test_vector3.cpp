#include "amumath/Vector3.h"
#include <gtest/gtest.h>

// Test Fixture: Clean way to organize tests
class Vector3Test : public ::testing::Test {
protected:
  amumath::Vector3 zero{0.0f, 0.0f, 0.0f};
  amumath::Vector3 unitX{1.0f, 0.0f, 0.0f};
  amumath::Vector3 unitY{0.0f, 1.0f, 0.0f};
  amumath::Vector3 unitZ{0.0f, 0.0f, 1.0f};
  amumath::Vector3 v1{1.0f, 2.0f, 3.0f};
  amumath::Vector3 v2{4.0f, 5.0f, 6.0f};
};

// Test Construction

TEST_F(Vector3Test, HandlesConstruction) {
  // Default constructor should be the zero vector
  amumath::Vector3 def;

  EXPECT_TRUE(def == zero);

  // Test 3 param constructor
  amumath::Vector3 custom{1.0f, 2.0f, 3.0f};
  // Test each param
  EXPECT_EQ(custom.x, 1.0f);
  EXPECT_EQ(custom.y, 2.0f);
  EXPECT_EQ(custom.z, 3.0f);
}

// Test vector equality == and inequality !=
TEST_F(Vector3Test, HandlesEquality) {

  // Exact equality
  amumath::Vector3 exact = {1.0f, 2.0f, 3.0f};
  EXPECT_TRUE(v1 == exact);

  // Different
  amumath::Vector3 distinct = {1.0f, 2.1f, 3.1f};
  EXPECT_TRUE(v1 != distinct);

  // Smaller than epsilon < e-6
  amumath::Vector3 tiny_diff = {1.0f, 2.0f + 1e-7f, 3.0f};

  // Since it is smaller than our epsilon it should be considered equal
  EXPECT_TRUE(v1 == tiny_diff);

  // Greater than epsilon > e-6
  amumath::Vector3 big_diff = {1.0f, 2.0f + 1e-5f, 3.0f};

  // Since greater than our epsilon should not be considered equal
  EXPECT_FALSE(v1 == big_diff);
}

// Test vector arithmetic (+ and -)
TEST_F(Vector3Test, HandlesAdditionSubtraction) {
  amumath::Vector3 sum = v1 + v2;  // (1 + 4, 2 + 5, 3 + 6)
  amumath::Vector3 diff = v2 - v1; // (4 - 1, 5 - 2, 6 - 3)
  amumath::Vector3 neg = -v1;      // (-1, -2, -3)
    
  // Test addition
  EXPECT_FLOAT_EQ(sum.x, 5.0f);
  EXPECT_FLOAT_EQ(sum.y, 7.0f);
  EXPECT_FLOAT_EQ(sum.z, 9.0f);
  // Test subtraction (difference) 
  EXPECT_FLOAT_EQ(diff.x, 3.0f);
  EXPECT_FLOAT_EQ(diff.y, 3.0f);
  EXPECT_FLOAT_EQ(diff.z, 3.0f);
  // Test negative
  EXPECT_FLOAT_EQ(neg.x, -1.0f);
  EXPECT_FLOAT_EQ(neg.y, -2.0f);
  EXPECT_FLOAT_EQ(neg.z, -3.0f);

}
