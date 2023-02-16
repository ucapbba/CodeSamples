#pragma once
#include <iostream>
#include <omp.h>
#include <vector>
#include <stdlib.h>     //for using the function sleep
using namespace std;
void DoBigTask()
{
    cout << " Doing big task " << endl;
    _sleep(2000);
}

void pushback(std::vector<int>* BinorbInd,int i)
{
    cout << " pushin back " << i << endl;
    BinorbInd->push_back(i);
    _sleep(200);
}

void OMP_push_back()
{
    //FRAN-184
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
            DoBigTask(); //parallel regrion
            #pragma omp critical //this ensures only 1 thread at a time pushes back 
            pushback(BinorbInd, i);
        }
        #pragma omp barrier //ensures all threads a done in parallel loop
        #pragma omp single  //single thread
        cout << "Bin size = "<<BinorbInd->size() << endl;
    }
}

void Simple_For()
{
    //compile with VS 142 toolset - 4 secs with vs 12 secs without 
    //omp_get_thread_num always returns 0
    //also improvement with LLVM toolset (require -openmp additional flag)
clock_t t = clock();
#pragma omp parallel for //ordered
    for (int i = 0; i < 20; ++i)
    {
        cout << "iteration = " << i << " omp_get_thread_num = " << omp_get_thread_num() << endl;
        for (int j = 0; j < 1000000000; ++j)
        {
            //cout << j << " ";
        }

    }

    float sec = ((float)(clock() - t)) / CLOCKS_PER_SEC;
    cout << "Timer: " << long(sec) / 3600 << "h " << long(sec) % 3600 / 60 << "min " << (long(sec * 100) % 6000) / 100.0 << "sec\n";
}