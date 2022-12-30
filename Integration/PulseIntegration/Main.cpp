// PulseIntegration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/numeric/odeint.hpp>
#include <fstream>
#include <sstream>
#include "Pulse.h"
#include "InputOutput.h"
#include "Consts.h"

using namespace std;
using namespace boost::numeric::odeint;

typedef runge_kutta_dopri5< double > stepper_type;

int main()
{
    InputOutput::clear_file("output.txt");
    double x = 0.0;
    integrate_adaptive(make_controlled(1E-12, 1E-12, stepper_type()),
        Pulse(nCycle,phi,Up), x, 0.0, nCycle*2*Pi, 0.1, InputOutput::write_cout);
}

