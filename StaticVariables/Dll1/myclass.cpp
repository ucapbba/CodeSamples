#include "pch.h"
#include "myclass.h"

double myclass::variable;

void myclass::AppendVariable()
{
	variable +=1;
}

double myclass::GetVariable()
{
	return variable;
}