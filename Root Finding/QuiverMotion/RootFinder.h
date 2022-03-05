#pragma once
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
class RootFinder
{
public:
 /*   int quiver_f(const gsl_vector * coords, void *params,
        gsl_vector * f);*/
    void  print_state(size_t iter, gsl_multiroot_fsolver * s, double t0, double w);
    double GetReturnTime(double E0, double w, double t0);

};

