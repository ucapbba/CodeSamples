// LambdaIntegrationExample.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <boost/numeric/odeint/integrate/integrate.hpp>

//#include <numeric>
//#include <functional>
//#include <boost/range/combine.hpp>
//#include <boost/numeric/odeint.hpp>
#define _USE_MATH_DEFINES
#include <math.h>

using namespace boost::numeric::odeint;
double myfunc(double x)
{
	return std::sin(x);
}
int main()
{
	auto lambda_func =[](double x)
	{
		return  myfunc(x);
	};
	double output;
	const double start = 0.01;
	const double end = 23;
	const double dx = 0.1;

	integrate(lambda_func, output, start, end,dx);
}


