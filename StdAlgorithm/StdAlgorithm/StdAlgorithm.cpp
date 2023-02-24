// StdAlgorithm.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Functions.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <list>

using namespace std;

void sort_test()
{
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
}

void other_std()
{
	std::vector<double> inVector;
	std::vector<double> outVector(5);
	inVector.push_back(1.0);
	inVector.push_back(2.0);
	inVector.push_back(3.0);
	inVector.push_back(4.0);
	inVector.push_back(5.0);

	std::sort(inVector.begin(), inVector.end(), myfunction);
	double y = 2;
	std::transform(inVector.begin(), inVector.end(), outVector.begin(), [y](double x) { return x * y; });

	std::adjacent_difference(outVector.begin(), outVector.end(), outVector.begin(), std::plus<double>()); //sums pairs 
	std::adjacent_difference(outVector.begin(), outVector.end(), outVector.begin()); //diff of pairs 

	std::transform(outVector.begin(), outVector.end(), outVector.begin(), outVector.begin(), std::multiplies<double>()); //multiply of pairs 
	double outVecSum = std::accumulate(outVector.begin() + 1, outVector.end(), 0.);
}

void lambda_functions()
{
	//Example 1
	std::vector<int> nums{ 3, 4, 2, 8, 15, 267 };
	auto print = [](const int& n) { std::cout << " " << n; };
	std::cout << "before:";
	std::for_each(nums.cbegin(), nums.cend(), print);
	std::cout << '\n';
	std::for_each(nums.begin(), nums.end(), [](int& n) { n++; });
	// calls Sum::operator() for each number
	Sum s = std::for_each(nums.begin(), nums.end(), Sum());
	std::cout << "after: ";
	std::for_each(nums.cbegin(), nums.cend(), print);
	std::cout << '\n';
	std::cout << "sum: " << s.sum << '\n';
}

void lambda_functions2()
{
	//Example 1
	// Create a list of integers with a few initial elements.
	list<int> numbers;
	numbers.push_back(13);
	numbers.push_back(17);
	numbers.push_back(42);
	numbers.push_back(46);
	numbers.push_back(99);

	// Use the find_if function and a lambda expression to find the
	// first even number in the list.
	const list<int>::const_iterator result =
		find_if(numbers.begin(), numbers.end(), [](int n) { return (n % 2) == 0; });

	// Print the result.
	if (result != numbers.end()) {
		cout << "The first even number in the list is " << *result << "." << endl;
	}
	else {
		cout << "The list contains no even numbers." << endl;
	}
}

int main()
{
	sort_test();
	
	other_std();

	lambda_functions();

	lambda_functions2();
}
