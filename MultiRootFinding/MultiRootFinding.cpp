#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

struct rparams
{
    double a;
    double b;
};

int rosenbrock_f(const gsl_vector * coords, void *params,
    gsl_vector * f)
{
    double a = ((struct rparams *) params)->a;
    double b = ((struct rparams *) params)->b;

    const double x = gsl_vector_get(coords, 0);
    const double y = gsl_vector_get(coords, 1);

    const double f1 = a * (1 - x);
    const double f2 = b * (y - x * x);

    gsl_vector_set(f, 0, f1);
    gsl_vector_set(f, 1, f2);

    return GSL_SUCCESS;
}

void  print_state(size_t iter, gsl_multiroot_fsolver * s)
{
    printf("iter = %3u x = % .3f y = % .3f "
        "f1(x,y) = % .3e f2(x,y) % .3e\n",
        iter,
        gsl_vector_get(s->x, 0), //x
        gsl_vector_get(s->x, 1), //y
        gsl_vector_get(s->f, 0), //f1
        gsl_vector_get(s->f, 1)); //f2
}

int main()
{
    std::cout << "Hello World!\n";
    const gsl_multiroot_fsolver_type *T;
    gsl_multiroot_fsolver *s;

    int status;
    size_t i, iter = 0;

    const size_t n = 2;
    struct rparams p = { 1.0, 10.0 };
    gsl_multiroot_function f = { &rosenbrock_f, n, &p };

    double init_coords[2] = { -10.0, -5.0 };
    gsl_vector *coords = gsl_vector_alloc(n);

    gsl_vector_set(coords, 0, init_coords[0]);
    gsl_vector_set(coords, 1, init_coords[1]);

    T = gsl_multiroot_fsolver_dnewton;
    s = gsl_multiroot_fsolver_alloc(T, 2);
    gsl_multiroot_fsolver_set(s, &f, coords);

    print_state(iter, s);

    do
    {
        iter++;
        status = gsl_multiroot_fsolver_iterate(s);

        print_state(iter, s);

        if (status)   /* check if solver is stuck */
            break;

        status =
            gsl_multiroot_test_residual(s->f, 1e-7);
    } while (status == GSL_CONTINUE && iter < 1000);

    printf("status = %s\n", gsl_strerror(status));
    gsl_multiroot_fsolver_free(s);
    gsl_vector_free(coords);
    return 0;
}
