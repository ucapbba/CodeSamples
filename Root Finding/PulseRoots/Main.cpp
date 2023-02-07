// PulseRoots.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include "RootFinderPulse.h"
#include "Pulse.h"
#include "RootFuntions.h"
using namespace std;

void OutputPulse(Pulse myPulse,string filename)
{
    //output pulse
    std::ofstream outputTimesFile;
    outputTimesFile.open(filename);
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

void OutputRoots(std::vector<double> crossingTimesE,string filename)
{
    std::ofstream rootsFile;
    rootsFile.open(filename);
    std::vector<double>::iterator it;
    for (it = crossingTimesE.begin(); it != crossingTimesE.end(); it++)
    {
        rootsFile << *it << endl;
    }
    rootsFile.close();
}

int main()
{
    RootFinder rootFinder;
    int nCycle = 5;
    double phi =  0.5*M_PI;
    Pulse myPulse(5.574, phi, nCycle);
    double shift = 0.1 * M_PI;
    int startCycle = 0;
    OutputPulse(myPulse,"output/pulse.txt");
    //Find roots
    std::vector<double> crossingTimesA;
    for (int i = startCycle*2; i < 2*nCycle; i++)
    {
        double crossingTime = rootFinder.GetCrossingTime(myPulse, M_PI*i+shift, Afield);
        crossingTimesA.push_back(crossingTime/M_PI/2);
    }
    std::vector<double> crossingTimesE;
    for (int i = startCycle * 2; i < 2*nCycle; i++)
    {
        double crossingTime = rootFinder.GetCrossingTime(myPulse, M_PI * i+shift+0.25*M_PI, Efield);
        crossingTimesE.push_back(crossingTime / M_PI/2);
    }
    OutputRoots(crossingTimesE, "output/crossings.txt");
    std::vector<double> crossingTimesdE;
    for (int i = startCycle * 2; i < 2*nCycle; i++)
    {
        double crossingTime = rootFinder.GetCrossingTime(myPulse, M_PI * i+shift, dEfield);
        crossingTimesdE.push_back(crossingTime / M_PI/2);
    }
    OutputRoots(crossingTimesdE, "output/maxima.txt");
}
