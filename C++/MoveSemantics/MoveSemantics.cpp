// MoveSemantics.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <utility>

#include "DynamicBuffer.h"

void ProcessData(int& data) {
    std::cout << "Processing lvalue data: " << data << std::endl;
}

void ProcessData(int&& data) {
    std::cout << "Processing rvalue data: " << data << std::endl;
}

template <typename T>
void DataWrapper(T&& data) {
   ProcessData(std::forward<T>(data)); //we need to be careful to preserve original value categories - i.e an r value
   //ProcessData(data); //This case will call ProcessData(int& data)
}

// ---- Rule of Five demonstration (DynamicBuffer) ----
// Shows why a class owning a raw resource (heap memory) must implement all
// five special member functions: destructor, copy ctor/assignment, and
// move ctor/assignment.
void DemonstrateRuleOfFive()
{
    DynamicBuffer bufferA(5);
    bufferA.at(0) = 3.14;

    // Copy constructor: bufferB gets its own independent memory
    DynamicBuffer bufferB(bufferA);

    // Copy assignment: bufferC already exists, old memory is freed first
    DynamicBuffer bufferC(5);
    bufferC = bufferA;

    // Move constructor: bufferD steals bufferA's pointer, bufferA becomes empty
    DynamicBuffer bufferD(std::move(bufferA));

    // Move assignment: bufferC's old memory is freed, then it steals bufferB's pointer
    bufferC = std::move(bufferB);

    std::cout << "bufferD[0] = " << bufferD.at(0) << std::endl;
}

int main() {
    int x = 42;
    DataWrapper(5); // Should call ProcessData(int&&)
    DataWrapper(x); // Should call ProcessData(int&)

    DemonstrateRuleOfFive();

    return 0;
}
