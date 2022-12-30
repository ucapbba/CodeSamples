#pragma once
#include <string>
#include <vector>
#include "Pulse.h"
class InputOutput
{
public:
	static void write(const vec& x, const double t);
	static void clear_file(std::string outFile);
	static void populateVector(double time, double AInt);
	static void ClearVector();
	static std::vector<AIntContainer> AIntVector;

};

