#include "RootFinder.h"
#include <iostream>

struct rparams
{
    double E0;
    double omega;
    double t0;
};

int quiver_f(const gsl_vector * coords, void *params,
    gsl_vector * f)
{
    double E0 = ((struct rparams *) params)->E0;
    double w = ((struct rparams *) params)->omega;
    double t0 = ((struct rparams *) params)->t0;

    const double t = gsl_vector_get(coords, 0);

    //classical equation for electron motion in sinusoidal electric field 
    const double f1 = E0 / (w*w)*cos(w*t) + E0 / w * sin(w*t0)*(t - t0) - E0 / (w*w)*cos(w*t0);

    gsl_vector_set(f, 0, f1);

    return GSL_SUCCESS;
}

void  RootFinder::print_state(size_t iter, gsl_multiroot_fsolver * s, double t0, double w)
{
    double x = gsl_vector_get(s->x, 0);
    double f1 = gsl_vector_get(s->f, 0);

    printf("iter = %3u t = % .3f t0 = % .3f y = % .3f\n",
        iter,
        gsl_vector_get(s->x, 0) / M_PI / 2 * w, //t
        t0 / M_PI / 2 * w,
        gsl_vector_get(s->f, 0)); //y
}

double RootFinder::GetReturnTime(double E0, double w, double t0)
{
    const gsl_multiroot_fsolver_type *T;
    gsl_multiroot_fsolver *s;

    int status;
    size_t iter = 0;
    const size_t n = 1;

    struct rparams p = { E0, w, t0 };
    gsl_multiroot_function f = { &quiver_f, n, &p };

    double init_coords[1] = { 2 * M_PI / p.omega }; // expect return at field crossing
    gsl_vector *coords = gsl_vector_alloc(n);

    gsl_vector_set(coords, 0, init_coords[0]);

    //T = gsl_multiroot_fsolver_dnewton;
    T = gsl_multiroot_fsolver_hybrid;
    s = gsl_multiroot_fsolver_alloc(T, 1);
    gsl_multiroot_fsolver_set(s, &f, coords);

    //print_state(iter, s, t0, w);

    do
    {
        iter++;
        status = gsl_multiroot_fsolver_iterate(s);

        //print_state(iter, s, t0, w);

        //the function has many solutions so here we check they are not trivial and if so, push the initial search co-ords.
        if (abs(gsl_vector_get(s->x, 0) - t0) < 0.01)
        {
            init_coords[0] += 0.1*M_PI / w;
            gsl_vector_set(coords, 0, init_coords[0]);
            gsl_multiroot_fsolver_set(s, &f, coords);
            status = GSL_CONTINUE;
            continue;
        }

        // we expect a return within 2 laser cycles.
        if (abs(gsl_vector_get(s->x, 0) > 2 * M_PI / w))
        {
            init_coords[0] -= 0.1*M_PI / w;
            gsl_vector_set(coords, 0, init_coords[0]);
            gsl_multiroot_fsolver_set(s, &f, coords);
            status = GSL_CONTINUE;
            continue;
        }

        // we don't want -ve values
        if (abs(gsl_vector_get(s->x, 0) < 1))
        {
            init_coords[0] -= 0.1*M_PI / w;
            gsl_vector_set(coords, 0, init_coords[0]);
            gsl_multiroot_fsolver_set(s, &f, coords);
            status = GSL_CONTINUE;
            continue;
        }

        if (status)   /* check if solver is stuck */
            break;

        status =
            gsl_multiroot_test_residual(s->f, 1e-7);
    } while (status == GSL_CONTINUE && iter < 1000);


    double returnTime = gsl_vector_get(s->x, 0);
    gsl_multiroot_fsolver_free(s);
    gsl_vector_free(coords);
    printf("status = %s\n", gsl_strerror(status));
    if (status == GSL_SUCCESS)
    {
        std::cout << "t0 = " << t0 << " return time = " << returnTime << std::endl;
        return returnTime;
    }
    else 
        return -1;
}