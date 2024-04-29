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

//reading lines from a text file

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
