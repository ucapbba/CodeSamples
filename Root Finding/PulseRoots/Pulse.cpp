#include "Pulse.h"
#include <math.h>
using namespace std;
double Pulse::GetAField(double t)
{
	return 2 * sqrt(up0) * pow(sin(t / 2 / nCycle), 2) * sin(t + phi);
}

double Pulse::GetEField(double t)
{
	int n = nCycle;
	double taddphi = t + phi;
	double tDiv2n = t / 2 / n;
	return -2*sqrt(up0)*cos(taddphi)*pow(sin(tDiv2n), 2) -2* sqrt(up0)/n*cos(tDiv2n)*sin(tDiv2n)*sin(taddphi);
}

double Pulse::GetdEField(double t)
{
	int n = nCycle;
	double tDivN = t / n;
	int nsub1sq = (-1 + n) * (-1 + n);
	int nadd1sq = (1 + n) * (1 + n);
	int twonsq = 2 * n * n;
	double taddphi = t + phi;
	return -sqrt(up0)/twonsq* (-twonsq*sin(taddphi)+nsub1sq*sin(taddphi-tDivN)+ nadd1sq*sin(taddphi+tDivN));
}
