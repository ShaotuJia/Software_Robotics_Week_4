/**
 * @Brief This file is to test PID class
 * @copyright, Shaotu Jia, All rights reserved
 */

#include <gtest/gtest.h>
#include <memory>
#include <cmath>

#define private public
#include "PID.hpp"



class PIDTest : public ::testing::Test {
 protected:
  virtual void SetUp() {
  }

  virtual void TearDown() {
  }
};

/**
 * @Brief The following test is to test whether the configuration works well
 */
TEST(PIDTest, ConfigurationTest) {
  auto p = std::make_unique<PID>(1);
  EXPECT_EQ(1, p->setpoint);    ///< test setpoint

  p->tuning(1, 2, 3);
  EXPECT_EQ(1, p->Kp);    ///< test Kp
  EXPECT_EQ(2, p->Ki);    ///< test Ki
  EXPECT_EQ(3, p->Kd);    ///< test Kd
}

/**
 * @Brief The following test is to test the member function get_error in PID class
 */
TEST(PIDTest, FunctionTest) {
  double input = 1;   ///< Input value for setpoint
  auto p = std::make_unique<PID>(input);
  p ->get_error(p->process_variable);
  EXPECT_EQ(input - p->process_variable, p->e_c);
}

#undef private

/**
 * @Brief The following test is to test the final output of the function
 */
TEST(PIDTest, ComputationTest) {
  double input = 1;   ///< Input value for setpoint
  auto p = std::make_unique<PID>(input);
  /**
   * !!! change the tuning parameter to pass the last test !!
   */
  p->tuning(0.1, 0.1, 0);
  p->compute();
  EXPECT_LT(std::abs(p->output - input), 0.1);
}
