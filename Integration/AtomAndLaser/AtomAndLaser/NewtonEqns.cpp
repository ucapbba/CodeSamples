#include "NewtonEqns.h"
#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/vector.hpp>


potParams::potParams(double a1_, double a2_, double a3_, double a4_, double a5_, double a6_)
    : a1(a1_), a2(a2_), a3(a3_), a4(a4_), a5(a5_), a6(a6_) {};

double f(double rr, potParams& p) {
    double a1 = p.a1, a2 = p.a2, a3 = p.a3, a4 = p.a4, a5 = p.a5, a6 = p.a6;
    return a1 * std::exp(-a2 * rr) + a3 * rr*std::exp(-a4 * rr) + a5 * std::exp(-a6 * rr);
}

double fp(double rr, potParams& p) {
    double a1 = p.a1, a2 = p.a2, a3 = p.a3, a4 = p.a4, a5 = p.a5, a6 = p.a6;
    return -a1 * a2*std::exp(-a2 * rr) + a3 * (1. - a4 * rr)*std::exp(-a4 * rr) - a5 * a6*std::exp(-a6 * rr);
}

NewtonEqns::NewtonEqns()
{
     w = 0.057;
     Ip = 0.5;
     Up = 1;
     rtUp = std::sqrt(Up);
     C = 1;
}

void NewtonEqns::operator()(const phase_space& x, phase_space& dxdt, const double t) {


	dxdt[0] = x[2] +2 * rtUp*std::sin(w*t); //dx/dt = 
    dxdt[1] = x[3];                        //dy/dt = p_x

	double Norm = 0;
	bool effectivePotential = false;

	if (effectivePotential)
	{
		double rr = std::sqrt(x[0] * x[0] + x[1] * x[1]);
		potParams p(16.039, 2.007, -25.543, 4.525, 0.961, 0.443);
		//potParams p(0.0, 0.0, 0.0, 0.0, 0.0, 0.0);
		Norm = -(C + f(rr, p) - rr * fp(rr, p)) / (rr*rr*rr);
	}
	else {  //softcore
		double a = 0.025;
		double rra = std::sqrt(x[0] * x[0] + x[1] * x[1] + a * a);
		Norm = -C / (rra*rra*rra);
	}
	

    dxdt[2] = x[0] * Norm; //dp_x/dt = delta(V)
    dxdt[3] = x[1] * Norm; //dp_y/dt = delta(V)
}


