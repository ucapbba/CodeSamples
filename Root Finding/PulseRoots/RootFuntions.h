#pragma once
#include <gsl/gsl_vector.h>
#include <gsl/gsl_multiroots.h>
#include "Pulse.h"

int Afield(const gsl_vector* coords, void* params,
    gsl_vector* f)
{
    Pulse* myPulse = (Pulse*)params;
    const double t = gsl_vector_get(coords, 0);
    const double f1 = myPulse->GetAField(t);
    gsl_vector_set(f, 0, f1);
    return GSL_SUCCESS;
}

int Efield(const gsl_vector* coords, void* params,
    gsl_vector* f)
{
    Pulse* myPulse = (Pulse*)params;
    const double t = gsl_vector_get(coords, 0);
    const double f1 = myPulse->GetEField(t);
    gsl_vector_set(f, 0, f1);
    return GSL_SUCCESS;
}

int dEfield(const gsl_vector* coords, void* params,
    gsl_vector* f)
{
    Pulse* myPulse = (Pulse*)params;
    const double t = gsl_vector_get(coords, 0);
    const double f1 = myPulse->GetdEField(t);
    gsl_vector_set(f, 0, f1);
    return GSL_SUCCESS;
}

