#include "RootFinderPulse.h"
#include "Pulse.h"
#include <iostream>



double RootFinder::GetCrossingTime(Pulse myPulse,double guess, int (*func)(const gsl_vector* coords, void* params, gsl_vector* f))
{
    const gsl_multiroot_fsolver_type *T;
    gsl_multiroot_fsolver *s;

    int status;
    size_t iter = 0;
    const size_t n = 1;

    gsl_multiroot_function f = { func, n, &myPulse };

    double init_coords[1] = { guess }; // expect return at 1st field crossing
    gsl_vector *coords = gsl_vector_alloc(n);

    gsl_vector_set(coords, 0, init_coords[0]);
    T = gsl_multiroot_fsolver_hybrid;
    s = gsl_multiroot_fsolver_alloc(T, 1);
    gsl_multiroot_fsolver_set(s, &f, coords);


    do
    {
        iter++;
        status = gsl_multiroot_fsolver_iterate(s);
        if (status)   /* check if solver is stuck */
            break;

        // we don't want -ve values
        if (abs(gsl_vector_get(s->x, 0) < 0))
        {
            init_coords[0] += 0.05 * M_PI;  //TODO - this value can break the solver if not chosen well
            gsl_vector_set(coords, 0, init_coords[0]);
            gsl_multiroot_fsolver_set(s, &f, coords);
            status = GSL_CONTINUE;
            continue;
        }

        status =
            gsl_multiroot_test_residual(s->f, 1e-12);
    } while (status == GSL_CONTINUE && iter < 1000);


    double returnTime = gsl_vector_get(s->x, 0);
    gsl_multiroot_fsolver_free(s);
    gsl_vector_free(coords);
    printf("status = %s\n", gsl_strerror(status));
    if (status == GSL_SUCCESS)
    {
        std::cout << "return time = " << returnTime << std::endl;
        return returnTime;
    }
    else 
        return -1;
}