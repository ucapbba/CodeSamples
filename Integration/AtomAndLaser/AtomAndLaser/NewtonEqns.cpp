#include "NewtonEqns.h"
#include <boost/numeric/ublas/blas.hpp>
#include <boost/numeric/ublas/vector.hpp>
#include <cmath>

const double pi = 3.142;

NewtonEqns::NewtonEqns(bool isCoulomb, bool isCos7, bool isVolker ) : Coulomb(isCoulomb), Cos7(isCos7), Volker(isVolker)
{
     w = 0.057;
     Ip = 0.5;
     Up = 1;
     rtUp = std::sqrt(Up);
     C = 1;
}

NewtonEqns::NewtonEqns()
{

}

void NewtonEqns::operator()(const phase_space& x, phase_space& dxdt, const double t) {


	dxdt[0] = x[2];// +2 * rtUp * std::sin(w * t); //dx/dt = 
    dxdt[1] = x[3];                        //dy/dt = p_x

	double Norm = 0;
	
	double a = 0.01; //softcore
	double rra = std::sqrt(x[0] * x[0] + x[1] * x[1] + a * a);
	double rr = std::sqrt(x[0] * x[0] + x[1] * x[1]);
	double r0 = 3; //Volker and Cos7
	double L =6; //cos7
	Norm = -1 / (rra * rra * rra);
	if (Coulomb)
	{

	}
	else if (Cos7)
	{
		if (rr > L)
		{
			Norm = 0;
		}
		else if (rr > r0 && rr <= L)
		{
			Norm = -7 * pi / (2 * (L - r0) * (rr * rr)) * pow(cos(0.5 * pi * (rr - r0) / (L - r0)), 6) * sin(0.5 * pi * (rr - r0) / (L - r0));
			Norm -= 1 / (rr * rr * rr) * pow(cos(0.5 * pi * (rr - r0) / (L - r0)), 7);
		}
	}
	else if (Volker)
	{
		if (rr > 2 * r0)
		{
			Norm = 0;
		}
		else if (rr > r0 && rr <= 2 * r0)
		{
			double m = 1 / r0 / r0 / rr;
			Norm = -m;
		}
	}
	else
	{
		Norm = 0;
	}


    dxdt[2] = x[0] * Norm; //dp_x/dt = delta(V)
    dxdt[3] = x[1] * Norm; //dp_y/dt = delta(V)
}


