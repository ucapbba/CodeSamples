// ExampleForSort.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <chrono>

void generateRandomNumbers(std::vector<int>& vec, int size) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 10000);

    vec.clear();
    vec.reserve(size);
    for (int i = 0; i < size; ++i) {
        vec.push_back(dis(gen));
    }
}


void measurePerformance(const std::vector<int>& vec, const std::string& description) {
    auto start = std::chrono::high_resolution_clock::now();
    std::vector<int> sortedVec = vec;
    std::sort(sortedVec.begin(), sortedVec.end());
    auto end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> sortDuration = end - start;
    std::cout << "Time taken to sort " << description << ": " << sortDuration.count() << " seconds\n";

    start = std::chrono::high_resolution_clock::now();
    bool isSorted = std::is_sorted(sortedVec.begin(), sortedVec.end());
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> checkDuration = end - start;
    std::cout << "Time taken to check if sorted " << description << ": " << checkDuration.count() << " seconds\n";
    std::cout << "Array is sorted: " << (isSorted ? "true" : "false") << "\n";

    if (description == "already sorted array") {
        std::cout << "Performance improvement for checking sorted array: "
            << (sortDuration.count() / checkDuration.count()) << " times faster\n";
    }
}

int main()
{
    const int size = 10000000;
    std::vector<int> vec;
    generateRandomNumbers(vec, size);

    std::cout << "Performance with random array:\n";
    measurePerformance(vec, "random array");

    std::cout << "\nPerformance with already sorted array:\n";
    std::sort(vec.begin(), vec.end());
    measurePerformance(vec, "already sorted array");

    return 0;
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
