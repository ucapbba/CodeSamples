#include "SomeClass.h"
#include <iostream>
#include <vector>
using namespace std;

void SomeClass::DoStuff()
{
	cout << "Doing stuff" << endl;
   int N = 8;
    int NThreads = 4;
    std::vector<int>* BinorbInd = new std::vector<int>;
    BinorbInd->reserve(N); //required to stop crash, however for big arrays use ordered
    //#pragma omp parallel for ordered num_threads(NThreads) ??
    #pragma omp parallel num_threads(NThreads) 
    {
        #pragma omp for 
        for (int i = 0; i < N; ++i)
        {   
            #pragma omp critical //this ensures only 1 thread at a time pushes back 
            BinorbInd->push_back(i);
        }
    }
}