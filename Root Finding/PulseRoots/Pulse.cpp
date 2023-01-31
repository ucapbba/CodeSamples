#include "Pulse.h"
#include <math.h>
using namespace std;
double Pulse::GetAField(double t)
{
	return 2 * sqrt(up0) * pow(sin(t / 2 / nCycle), 2) * sin(t + phi);
}

