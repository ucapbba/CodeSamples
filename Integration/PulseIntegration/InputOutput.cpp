#include "InputOutput.h"
#include "Consts.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Pulse.h"

using namespace std;

std::vector<AIntContainer> InputOutput::AIntVector;

void InputOutput::write(const vec& x, const double t)
{
    Pulse pulse(nCycle, phi, Up);
    cout << t << '\t' << x[0] << '\t' << x[1] << '\t' << pulse.Afield(t) << '\t' << pulse.Afield(t) << endl;
   
    std::ofstream outputFile;
    outputFile.open("output.txt", std::ios_base::app);
    outputFile << t / 2 / Pi << '\t' << x[0] << '\t' << x[1] << '\t'<< pulse.Afield(t)<< '\t' << pulse.A2field(t) << '\n';;
    outputFile.close();

    populateVector(t, x[0]);
}

void InputOutput::populateVector(double time, double AInt)
{
    AIntContainer container(time,AInt);
   
    AIntVector.push_back(container);
}


void InputOutput::ClearVector()
{
    AIntVector.clear();
}

void InputOutput::clear_file(string outFile)
{
    std::ofstream ofs;
    ofs.open(outFile, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}