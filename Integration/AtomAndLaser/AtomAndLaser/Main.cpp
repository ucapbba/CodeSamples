// AtomAndLaser.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/numeric/odeint.hpp>
//#include <boost/numeric/odeint/stepper/generation/make_controlled.hpp>
//#include <boost/numeric/odeint/stepper/runge_kutta_fehlberg78.hpp>
//#include <boost/phoenix/core.hpp>
//#include <boost/phoenix/operator.hpp>
#include "NewtonEqns.h"
#include "boost/numeric/odeint/integrate/integrate.hpp"
#include <fstream>
using namespace std;
using namespace boost::numeric::odeint;

struct push_back_state_and_time
{
    std::vector< phase_space >& m_states;
    std::vector< double >& m_times;

    push_back_state_and_time(std::vector< phase_space > &states, std::vector< double > &times)
        : m_states(states), m_times(times) { }

    void operator()(const phase_space &x, double t)
    {
        m_states.push_back(x);
        m_times.push_back(t);
    }
};

int main()
{
    phase_space ps(4);
    ps[0] = 5.0; //x0
    ps[1] = 1.0;//y0
    ps[2] = 0.1; //px0
    ps[3] = 0.1;//py0

    std::cout << "Hello World!\n";
    double t0 = 0;
    double tf = 200;
    double dt = 0.01;
    vector<phase_space> x_vec;
    vector<double> times;

    NewtonEqns Newton;
    //Todo - CQSFA code returns x - need to understand what this is
    //integrate_adaptive(make_controlled< error_stepper_type2 >(abs_err, rel_err), NewtEq, x, t0, tf, dt);
   size_t steps = integrate(Newton,
        ps, t0, tf, dt,
        push_back_state_and_time(x_vec, times));

   std::ofstream outputFile;
   outputFile.open("output.txt");
   for (size_t i = 0; i <= steps; i++)
   {
       cout << times[i] << '\t' << x_vec[i][0] << '\t' << x_vec[i][1] << '\n';
       outputFile << times[i] << '\t' << x_vec[i][0] << '\t' << x_vec[i][1] << '\n';;
   }
   outputFile.close();
}
