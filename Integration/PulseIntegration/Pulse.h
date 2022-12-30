#pragma once
#include <math.h>
#include <vector>
#include <boost/numeric/odeint.hpp>
#include <complex>

typedef std::vector<double> vec;
typedef  std::complex<double> dcmplx;

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
    void operator()(const dcmplx& x, dcmplx& dxdt, const dcmplx t) const;
    double Afield(double t) const;
    dcmplx Afield(dcmplx t) const;
    double A2field(double t) const;
    dcmplx A2field(dcmplx t) const;

private:
    int nCycles;
    double phi;
    double Up;
};