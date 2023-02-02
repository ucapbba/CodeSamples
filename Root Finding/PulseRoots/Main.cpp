// PulseRoots.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "RootFinderPulse.h"
#include "Pulse.h"
#include "RootFuntions.h"

void OutputPulse(Pulse myPulse)
{
    //output pulse
    std::ofstream outputTimesFile;
    outputTimesFile.open("outputTimes.txt");
    double dt = 0.01;
    int n = myPulse.GetCycle();
    for (int i = 0; i < (int)n * 2 * M_PI / dt; ++i)
    {
        double t = i * dt;
        double Afield = myPulse.GetAField(t);
        double Efield = myPulse.GetEField(t);
        double dEfield = myPulse.GetdEField(t);

        outputTimesFile << t/2/M_PI << "  " << Afield << " " << Efield << " " << dEfield << std::endl;
    }
    outputTimesFile.close();
}

int main()
{
    RootFinder rootFinder;
    int nCycle = 5;
    double phi = 00;
    Pulse myPulse(5.574, phi, nCycle);
 
    OutputPulse(myPulse);
    //Find roots
    std::vector<double> crossingTimesA;
    for (int i = 0; i < 2*nCycle; i++)
    {
        double crossingTime = rootFinder.GetCrossingTime(myPulse, M_PI*i, Afield);
        crossingTimesA.push_back(crossingTime/M_PI/2);
    }
    std::vector<double> crossingTimesE;
    for (int i = 0; i < 2*nCycle; i++)
    {
        double crossingTime = rootFinder.GetCrossingTime(myPulse, M_PI * i+0.25*M_PI, Efield);
        crossingTimesE.push_back(crossingTime / M_PI/2);
    }
    std::vector<double> crossingTimesdE;
    for (int i = 0; i < 2*nCycle; i++)
    {
        double crossingTime = rootFinder.GetCrossingTime(myPulse, M_PI * i, dEfield);
        crossingTimesdE.push_back(crossingTime / M_PI/2);
    }
}
