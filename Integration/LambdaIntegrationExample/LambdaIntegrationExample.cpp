// LambdaIntegrationExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/numeric/odeint/integrate/integrate.hpp>
#include <boost/range/combine.hpp>
#include <complex>

//#include <numeric>
//#include <functional>
//#include <boost/range/combine.hpp>
//#include <boost/numeric/odeint.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace boost::numeric::odeint;
using namespace std;
using dcmplx = std::complex<double>;
constexpr dcmplx I(0, 1.);
double myfunc(double x)
{
	return std::sin(x);
}
int main()
{
	dcmplx ts = 0. + 10.*I;
	double xpt = 0;
	auto fv = [xpt,ts](dcmplx& V, dcmplx ti) {

		V = ti + ts;
	};

	double teps = 1e-12;
	dcmplx Sv0 = 0. + 0.*I;

	double ddt = 0.1; //TODO
	boost::numeric::odeint::integrate(fv, Sv0, teps, ts.imag(), ddt);


	//double phi = 2.0;
	//auto lambda_func =[&phi](double x)
	//{
	//	return x;
	//};
	//double output;
	//double start = 0.01;
	//double end = 23;
	//double dx = 0.1;

	//integrate(lambda_func, output, start, end,dx);
}


