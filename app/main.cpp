#include <iostream>
#include "PID.hpp"

int main()
{
    /**
     * configuration part
     */
    //auto p = std::make_unique<PID>(1);  ///< Intialize PID class and set up setpoint
    //p->tuning(1.0, 1.0, 1.0);

    /**
     * computation part
     */
    //p->compute();
    PID p(1);
    p.tuning(1,0.1,0.1);
    p.compute();
}
