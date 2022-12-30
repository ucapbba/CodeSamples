#pragma once
#include <math.h>
class Pulse
{
public:
    Pulse(int _nCycles, double _phi, double _Up) : nCycles(_nCycles), phi(_phi), Up(_Up) {}
    void operator()(const double x, double& dxdt, const double t) const;
    double Afield(double t) const;
    double A2field(double t) const;

private:
    int nCycles;
    double phi;
    double Up;
};