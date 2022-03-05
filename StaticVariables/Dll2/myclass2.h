#pragma once
#include "../StaticLib1/myClassStatic.h"
class  __declspec(dllexport) myclass2
{
public:
	static double GetVariable()
	{
		return myClassStatic::GetVariable();
	}

};

