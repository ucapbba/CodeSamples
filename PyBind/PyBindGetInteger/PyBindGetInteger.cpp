// PyBindGetInteger.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "pyhelper.h"

int main()
{
	CPyInstance hInstance;

	CPyObject pName = PyUnicode_FromString("pyemb3");
	CPyObject pModule = PyImport_Import(pName);

	if (pModule)
	{
		CPyObject pFunc = PyObject_GetAttrString(pModule, "getInteger");
		if (pFunc && PyCallable_Check(pFunc))
		{
			CPyObject pValue = PyObject_CallObject(pFunc, NULL);
			long integer = PyLong_AsLong(pValue);
			printf_s("C: getInteger() = %ld\n", integer);
		}
		else
		{
			printf("ERROR: function getInteger()\n");
		}

	}
	else
	{
		printf_s("ERROR: Module not imported\n");
	}

	return 0;
}

