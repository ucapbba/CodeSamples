#include "InputOutput.h"
#include "Consts.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include "Pulse.h"

using namespace std;

void InputOutput::write_cout(const double& x, const double t)
{
    Pulse pulse(nCycle, phi, Up);
    cout << t << '\t' << x << '\t' << pulse.Afield(t) << endl;
   
    std::ofstream outputFile;
    outputFile.open("output.txt", std::ios_base::app);
    outputFile << t / 2 / Pi << '\t' << x << '\t'<< pulse.Afield(t)<< '\n';;
    outputFile.close();
}

void InputOutput::clear_file(string outFile)
{
    std::ofstream ofs;
    ofs.open(outFile, std::ofstream::out | std::ofstream::trunc);
    ofs.close();
}