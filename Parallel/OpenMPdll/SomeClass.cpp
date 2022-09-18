#include "SomeClass.h"
#include <iostream>
#include <vector>
using namespace std;

void SomeClass::DoStuff()
{
	cout << "Doing stuff" << endl;
    int N = 10000000;
    std::vector<int>* BinorbInd = new std::vector<int>;
    BinorbInd->reserve(N); //required to stop crash, however for big arrays use ordered
    //#pragma omp parallel for ordered num_threads(N)
    #pragma omp parallel for num_threads(N)
    for (int i = 0; i < N; ++i)
    {
        //cout << i << endl;
        BinorbInd->push_back(i);
    }
    #pragma omp ordered
    cout << BinorbInd->size() << endl;
}