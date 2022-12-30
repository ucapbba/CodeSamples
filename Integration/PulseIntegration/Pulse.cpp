#include "Pulse.h"
#include <vector>

void Pulse::operator()(const double x, double& dxdt, const double t) const
{
    dxdt = Afield(t);
}

double Pulse::Afield(double t) const
{
    return 2 * sqrt(Up) * pow(sin(t / 2 / nCycles), 2) * sin(t + phi);
}

double Pulse::A2field(double t) const
{
    return pow(Afield(t), 2);
}