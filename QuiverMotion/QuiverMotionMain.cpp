#include <iostream>
#include <fstream>
#include <sstream>
#include "RootFinder.h"
int main()
{
    std::cout << "Hello World!\n";

    double w = 0.057;
    double E0 = 0.5;
    double t0_max = M_PI / 2 / w;
    double delta = 0.1;
    RootFinder rootFinder;
    std::ofstream outputTimesFile;
    outputTimesFile.open("outputTimes.txt");

    for (int i = 0; i < int(t0_max / delta); ++i)
    {
        double t0 = i*delta;
        double returnTime = rootFinder.GetReturnTime(E0, w, t0);

        if(returnTime!=-1)
        outputTimesFile << t0 / (2*M_PI/w) << "  " << returnTime / (2 * M_PI / w) << std::endl;

    }

    outputTimesFile.close();

    return 0;
}



