#include "Pulse.h"

void Pulse::operator()(const vec& x, vec& dxdt, const double t) const
{
 /*   dxdt = Afield(t);*/
    dxdt[0] = Afield(t);
    dxdt[1] = A2field(t);
}

double Pulse::Afield(double t) const
{
    return 2 * sqrt(Up) * pow(sin(t / 2 / nCycles), 2) * sin(t + phi);
}

double Pulse::A2field(double t) const
{
    return pow(Afield(t), 2);
}