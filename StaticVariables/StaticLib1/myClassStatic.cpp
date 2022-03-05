#include "pch.h"
#include "myClassStatic.h"

double myClassStatic::variable;

void myClassStatic::AppendVariable()
{
	variable += 1;
}

double myClassStatic::GetVariable()
{
	return variable;
}