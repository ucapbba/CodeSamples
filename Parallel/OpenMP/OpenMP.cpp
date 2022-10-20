// OpenMP.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <omp.h>
#include <vector>
using namespace std;
int main()
{
    int NThreads = 8;
    int i = 100;

 //INCA - 1854
//#pragma region push_back
//
//    int N = 10000000;
//    std::vector<int>* BinorbInd = new std::vector<int>;
//    BinorbInd->reserve(N); //required to stop crash, however for big arrays use ordered
//    //#pragma omp parallel for ordered num_threads(NThreads)
//    #pragma omp parallel for num_threads(NThreads)
//    for (int i = 0; i < N; ++i)
//    {
//        //cout << i << endl;
//        BinorbInd->push_back(i);
//    }
//    #pragma omp ordered
//        cout << BinorbInd->size() << endl;
//#pragma endregion

    #pragma region Fran-189
vector<float> v = { 1, 2, 3, 4 };
vector<float> d = { 8, 7, 6, 5 };
int sum = 0;
#pragma omp parallel
        {
            auto it_v = v.begin(), it_d = d.begin();
#pragma openmp for 
            //for (; it_v != v.end(), it_d != d.end(); ++it_v, ++it_d)
            for (; it_v != v.end(); ++it_v)
            {
                cout << *it_v << " " << *it_d << endl;
                sum += *it_v + *it_d;
            }
        }
        cout << " sum = " << sum << endl;
#pragma endregion

#pragma region simple_firstprivate
//#pragma omp parallel firstprivate(i)
//    {
//        printf("thread %d: i = %d\n", omp_get_thread_num(), i);
//        i = 1000 + omp_get_thread_num();
//    }
#pragma endregion 

//#pragma omp parallel num_threads(NThreads)

#pragma region simple_for
//compile with VS 142 toolset - 4 secs with vs 12 secs without 
//omp_get_thread_num always returns 0
//also improvement with LLVM toolset (require -openmp additional flag)
clock_t t = clock();
//#pragma omp parallel for //ordered
//for (int i = 0; i < 20; ++i)
//    {
//       cout << "iteration = " << i << " omp_get_thread_num = " << omp_get_thread_num() << endl;
//        for (int j = 0; j < 1000000000; ++j)
//            {
//                //cout << j << " ";
//            }
//
//    }
//
//    float sec = ((float)(clock() - t)) / CLOCKS_PER_SEC;
//    cout << "Timer: " << long(sec) / 3600 << "h " << long(sec) % 3600 / 60 << "min " << (long(sec * 100) % 6000) / 100.0 << "sec\n";
#pragma endregion
}
