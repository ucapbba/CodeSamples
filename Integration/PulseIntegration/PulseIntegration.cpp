// PulseIntegration.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/numeric/odeint.hpp>
#include <fstream>
#include <sstream>
#include <math.h>

using namespace std;
using namespace boost::numeric::odeint;

const double Pi = 3.1415926535897932384626433832795028841971693993751;
const int nCycle = 2;

void rhs(const double x, double& dxdt, const double t)
{
    //dxdt = 3.0 / (2.0 * t * t) + x / (2.0 * t);
    dxdt = sin(t);
}

void write_cout(const double& x, const double t)
{
    cout << t << '\t' << x << endl;
    std::ofstream outputFile;
    outputFile.open("output.txt", std::ios_base::app);
    outputFile << t/2/Pi << '\t' << x << '\n';;
    outputFile.close();
}


void clear_file(string outFile)
{
    std::ofstream ofs;
    ofs.open(outFile, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}
// state_type = double
typedef runge_kutta_dopri5< double > stepper_type;

int main()
{
    clear_file("output.txt");
    double x = 0.0;
    integrate_adaptive(make_controlled(1E-12, 1E-12, stepper_type()),
        rhs, x, 0.0, nCycle*2*Pi, 0.1, write_cout);
}

