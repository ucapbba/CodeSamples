#include "Input.h"
#include <complex>
#define _USE_MATH_DEFINES
#include <math.h>
using namespace std;
namespace OrbitFinderCore
{
	Input::Input(double _omega, double Up, double E1g, double E2g, double E2e, double p_max, double p_min, double dp, 
		double p_perp_max, double p_perp_min, double dp_perp)
	{
		omega = _omega;
		_Up = Up;
		_E1g = E1g;
		_E2g = E2g;
		_E2e = E2e;

		_nTheta = 0; // = 0 cartesian
					 // != 0 radial

		timesShort.push_back(complex<double>(1.71343 / omega, 1.27339 / omega));  //t1
		timesShort.push_back(complex<double>(6.0649 / omega, -1.21389 / omega));  //t2
		timesShort.push_back(complex<double>(6.85759 / omega, 1.75491 / omega));  //t3

		timesLong.push_back(complex<double>(1.83515 / omega, 0.719401 / omega));  //t1
		timesLong.push_back(complex<double>(7.0701 / omega, 1.18486 / omega));  //t2
		timesLong.push_back(complex<double>(6.8 / omega, 1.75491 / omega));  //t3

		momRanges.push_back(p_min);   //parallel
		momRanges.push_back(p_max);
		momRanges.push_back(dp);
		momRanges.push_back(p_perp_min);   //perpendicular
		momRanges.push_back(p_perp_max);
		momRanges.push_back(dp_perp);


	}
	double Input::Omega() const { return omega; }
	double Input::Up() const { return _Up; }
	double Input::E1g() const { return _E1g; }
	double Input::E2g() const { return _E2g; }
	double Input::E2e() const { return _E2e; }

	complex<double>& Input::t1short() { return timesShort.at(0); }
	complex<double>& Input::t2short() { return timesShort.at(1); }
	complex<double>& Input::t3short() { return timesShort.at(2); }
	complex<double>& Input::t1long() { return timesLong.at(0); }
	complex<double>& Input::t2long() { return timesLong.at(1); }
	complex<double>& Input::t3long() { return timesLong.at(2); }
	vector<complex<double>> Input::AllTimes() { return timesShort; }

	double Input::p_Min() { return  momRanges.at(0); }
	double Input::p_Max() { return  momRanges.at(1); }
	double Input::dp() { return  momRanges.at(2); }
	int Input::p_Range()
	{
		return (int)std::round((p_Max() - p_Min()) / dp()) + 1;
	}
	double Input::p_Min_Perp() { return  momRanges.at(3); }
	double Input::p_Max_Perp() { return  momRanges.at(4); }
	double Input::dp_Perp() { return  momRanges.at(5); }
	int Input::p_Range_Perp()
	{
		return (int)std::round((p_Max_Perp() - p_Min_Perp()) / dp_Perp()) + 1;
	}

	int Input::nTheta() { return _nTheta; }
	double Input::dTheta()
	{
		return 2 * M_PI / _nTheta;
	}
}