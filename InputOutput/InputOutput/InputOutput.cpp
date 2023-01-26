// InputOutput.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iterator>
#include <fstream>
#include <sstream>
using namespace std;

int main()
{
    // Store the contents into a vector of strings
    std::vector<std::string> outputs;

    std::cout << "Reading from input.txt....\n";

    // Create the file object (input)
    std::ifstream infile("input.txt");
    if (!infile.is_open())
        return 1;
    // Temporary buffer
    std::string temp;

    // Get the input from the input file until EOF
    while (std::getline(infile, temp)) {
        // Add to the list of output strings
        outputs.push_back(temp);
    }

    // Use a range-based for loop to iterate through the output vector
    for (const auto& i : outputs)
        std::cout << i << std::endl;

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
