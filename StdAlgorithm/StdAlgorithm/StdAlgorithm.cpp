// StdAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

int main()
{
	std::vector<double> inVector;
	std::vector<double> outVector(5);
	inVector.push_back(1.0);
	inVector.push_back(2.0);
	inVector.push_back(3.0);
	inVector.push_back(4.0);
	inVector.push_back(5.0);
	double y = 2;
	std::transform(inVector.begin(), inVector.end(), outVector.begin(), [y](double x) { return x * y; });

	std::adjacent_difference(outVector.begin(), outVector.end(), outVector.begin(), std::plus<double>()); //sums pairs 
	std::adjacent_difference(outVector.begin(), outVector.end(), outVector.begin()); //diff of pairs 
	
	std::transform(outVector.begin(), outVector.end(), outVector.begin(), outVector.begin(), std::multiplies<double>()); //multiply of pairs 
	double outVecSum = std::accumulate(outVector.begin() + 1, outVector.end(), 0.);

    std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
