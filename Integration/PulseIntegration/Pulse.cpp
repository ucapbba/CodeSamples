#include "Pulse.h"

void Pulse::operator()(const vec& x, vec& dxdt, const double t) const
{
    dxdt[0] = Afield(t);
    dxdt[1] = A2field(t);
}

void Pulse::operator()(const dcmplx& x, dcmplx& dxdt, const dcmplx t) const
{
    dxdt = Afield(t);
}

double Pulse::Afield(double t) const
{
    return 2 * sqrt(Up) * pow(sin(t/2/nCycles), 2) * sin(t + phi);
}

double Pulse::A2field(double t) const
{
    return pow(Afield(t), 2);
}

dcmplx Pulse::Afield(dcmplx t) const
{
    return 2 * sqrt(Up) * pow(sin(t/2.0/(double)nCycles),2) * sin(t + phi);
}

dcmplx Pulse::A2field(dcmplx t) const
{
    return pow(Afield(t), 2);
}