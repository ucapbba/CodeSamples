// PulseRoots.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "RootFinderPulse.h"
#include "Pulse.h"

int main()
{
    RootFinder rootFinder;
    int nCycle = 5;
    double phi = 0.5;
    Pulse myPulse(5.574, phi, nCycle);
    std::vector<double> crossingTimes;

    for (int i = 1; i < nCycle; i++)
    {
        double crossingTime = rootFinder.GetCrossingTime(myPulse, M_PI*i);
        crossingTimes.push_back(crossingTime/M_PI);
    }
}
