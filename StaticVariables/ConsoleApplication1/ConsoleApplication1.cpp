// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "../Dll1/myclass.h"
#include "../Dll2/myclass2.h"
#include "../StaticLib1/myClassStatic.h"
int main()
{
	double variable = myclass::GetVariable();  //0
	myClassStatic::AppendVariable(); //+1
	variable = myClassStatic::GetVariable();  //1
	myClassStatic::AppendVariable(); //+1
	variable = myClassStatic::GetVariable(); //2
	myClassStatic::AppendVariable(); //+1
	variable = myclass2::GetVariable(); //3
	variable = myClassStatic::GetVariable(); //3
    std::cout << "Hello World!\n";
}
