#pragma once
#include <math.h>
#include <vector>
#include <boost/numeric/odeint.hpp>

typedef std::vector<double> vec;
struct AIntContainer
{
    AIntContainer(double _time, double _AInt) : time(_time), AInt(_AInt) {};
    double time;
    double AInt;
};

class Pulse
{
public:
    Pulse(int _nCycles, double _phi, double _Up) : nCycles(_nCycles), phi(_phi), Up(_Up) {}
    void operator()(const vec& x, vec& dxdt, const double t) const;
    double Afield(double t) const;
    double A2field(double t) const;

private:
    int nCycles;
    double phi;
    double Up;
};