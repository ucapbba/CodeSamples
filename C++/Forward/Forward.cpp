// Forward.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <utility>

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

int main() {
    int x = 42;
    DataWrapper(5); // Should call ProcessData(int&&)
    DataWrapper(x); // Should call ProcessData(int&)
    return 0;
}

