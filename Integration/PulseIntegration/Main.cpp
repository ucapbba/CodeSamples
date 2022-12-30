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
    InputOutput::ClearVector();
  /*  vec x = 0;*/
    vec x(2);
    x[0] = 0.0; //Afield
    x[1] = 0.0; //A2Field
    integrate( Pulse(nCycle,phi,Up), x, 0.0, nCycle*2*Pi, 0.1, InputOutput::write);

    //here add the logic to calculate the definte integral between 2 arbitrary times 
    double definiteIntegral = InputOutput::AIntVector[10].AInt - InputOutput::AIntVector[5].AInt;
}

