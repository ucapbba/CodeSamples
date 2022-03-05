/*
 Copyright 2009-2012 Karsten Ahnert
 Copyright 2009-2012 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#include <iostream>
#include <vector>
#include <boost/numeric/odeint.hpp>
#include <fstream>
#include <sstream>

 //[ rhs_function
 /* The type of container used to hold the state vector */
typedef std::vector< double > state_type;

const double gam = 0.15;

/* The rhs of x' = f(x) */
void harmonic_oscillator(const state_type &x, state_type &dxdt, const double /* t */)
{
    dxdt[0] = x[1];
    dxdt[1] = -x[0] - gam * x[1];
}
//]

//[ rhs_class
/* The rhs of x' = f(x) defined as a class */

//]

//[ integrate_observer
struct push_back_state_and_time
{
    std::vector< state_type >& m_states;
    std::vector< double >& m_times;

    push_back_state_and_time(std::vector< state_type > &states, std::vector< double > &times)
        : m_states(states), m_times(times) { }

    void operator()(const state_type &x, double t)
    {
        m_states.push_back(x);
        m_times.push_back(t);
    }
};
//]

struct write_state
{
    void operator()(const state_type &x) const
    {
        std::cout << x[0] << "\t" << x[1] << "\n";
    }
};


int main(int /* argc */, char** /* argv */)
{
    using namespace std;
    using namespace boost::numeric::odeint;

    //[ state_initialization
    state_type x(2);
    x[0] = 1.0; // start at x=1.0, p=0.0
    x[1] = 0.0;
    //]

    //[ integrate_observ
    vector<state_type> x_vec;
    vector<double> times;

    size_t steps = integrate(harmonic_oscillator,
        x, 0.0, 100.0, 0.1,
        push_back_state_and_time(x_vec, times));

    /* output */
    std::ofstream outputFile;
    outputFile.open("output.txt");
    for (size_t i = 0; i <= steps; i++)
    {
        cout << times[i] << '\t' << x_vec[i][0] << '\t' << x_vec[i][1] << '\n';
        outputFile << times[i] << '\t' << x_vec[i][0] << '\t' << x_vec[i][1] << '\n';;
    }
    outputFile.close();
    //]

#ifdef BOOST_NUMERIC_ODEINT_CXX11
//[ define_const_stepper_cpp11
    runge_kutta4< state_type > stepper;
    integrate_const(stepper, [](const state_type &x, state_type &dxdt, double t) {
        dxdt[0] = x[1]; dxdt[1] = -x[0] - gam * x[1]; }
    , x, 0.0, 10.0, 0.01);
    //]
#endif


}

