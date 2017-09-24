/**
 * @Brief This file is the main function that configure and run PID controller
 * @author Shaotu Jia
 * @copyright, Shaotu Jia, All rights reserved
 */


#include <iostream>
#include <memory>
#include "PID.hpp"

int main() {
/**
 * configuration part
 */
auto p = std::make_unique<PID>(1);  ///< Intialize PID class and set up setpoint
p->tuning(0.1, 0.1, 0);

/**
 * computation part
 */
p->compute();
}
