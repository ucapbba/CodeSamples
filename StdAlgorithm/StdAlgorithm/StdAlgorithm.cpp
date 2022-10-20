// StdAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

bool myfunction(int i, int j) { return (i > j); }

class initCondVars {
public:
	initCondVars(int a, int b);
	int variable1;
	int variable2;
};
initCondVars::initCondVars(int a, int b)
{
	variable1 = a;
	variable2 = b;
}
bool myfunctionInit1(initCondVars i, initCondVars j) { return (i.variable1 < j.variable1); }
bool myfunctionInit2(initCondVars i, initCondVars j) { return (i.variable2 > j.variable2); }
bool myfunctionInit3(initCondVars i, initCondVars j) { 
	if (i.variable1 != j.variable1)
	{
		return i.variable1 < j.variable1;
	}
	else
	{
		 i.variable1 > j.variable1;
	}
}
int main()
{


#pragma region sort_test
	initCondVars a1(5, 1);
	initCondVars a2(3, 2);
	initCondVars a3(3, 3);
	initCondVars a4(2, 4);
	initCondVars a5(1, 5);
	std::vector<initCondVars> sortVector;
	sortVector.push_back(a1);
	sortVector.push_back(a2);
	sortVector.push_back(a3);
	sortVector.push_back(a4);
	sortVector.push_back(a5);

	std::sort(sortVector.begin(), sortVector.end(), myfunctionInit3);
#pragma endregion	
	
#pragma region other_std

	std::vector<double> inVector;
	std::vector<double> outVector(5);
	inVector.push_back(1.0);
	inVector.push_back(2.0);
	inVector.push_back(3.0);
	inVector.push_back(4.0);
	inVector.push_back(5.0);

	//simple sort
	std::sort(inVector.begin(), inVector.end(), myfunction);
	double y = 2;
	std::transform(inVector.begin(), inVector.end(), outVector.begin(), [y](double x) { return x * y; });

	std::adjacent_difference(outVector.begin(), outVector.end(), outVector.begin(), std::plus<double>()); //sums pairs 
	std::adjacent_difference(outVector.begin(), outVector.end(), outVector.begin()); //diff of pairs 
	
	std::transform(outVector.begin(), outVector.end(), outVector.begin(), outVector.begin(), std::multiplies<double>()); //multiply of pairs 
	double outVecSum = std::accumulate(outVector.begin() + 1, outVector.end(), 0.);

#pragma endregion
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
