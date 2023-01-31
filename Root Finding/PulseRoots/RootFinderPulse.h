#pragma once
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include "Pulse.h"
class RootFinder
{
public:
    void  print_state(size_t iter, gsl_multiroot_fsolver * s, double t0, double w);
    double GetCrossingTime(Pulse myPulse, double guess);

};

