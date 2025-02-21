// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <algorithm>
#include <vector>
#include <iostream>
#include <string>
#include <tuple>
using namespace std;
class MyClass {
public:
    int value; // Integer member

    MyClass(int val) : value(val) {} // Constructor to initialize the integer member
};


bool IsEven(MyClass mclass)
{
    return (mclass.value % 2) == 0;
}

int main()
{

    std::vector<std::pair<const std::string&,double>> clausesOrdered = 
    {
      {"banana", 1},
      {"apple", 4},
      {"orange", 3}
    };


    std::sort(clausesOrdered.begin(), clausesOrdered.end(),
        [&](const auto& a, const auto& b) {
           return a.first < b.first;
        });


    //Basic Lambda
     // capture initial_sum by value
    //() -> function arguments
    //[] -> capture variables outside lambda definition, can be by reference otherwise copied
    int initial_sum = 100;
    auto add_to_sum = [initial_sum](int num) {
        // here inital_sum = 100 from local scope
        return initial_sum + num;
        };

    int final_sum = add_to_sum(78);
    //"100 + 78 = " << final_sum;

    //return 0;


    //Lamda function in STL
    std::vector<MyClass> numbers = { MyClass(1), MyClass(3), MyClass(5), MyClass(4), MyClass(6), MyClass(8) };
    // Use std::find_if with a lambda function to find the first object with an even integer member
    auto result = std::find_if(numbers.begin(), numbers.end(), IsEven);
    //replace IsEven with Lambda
    //& indicates capture by reference - could leave blank []
    auto result2 = std::find_if(numbers.begin(), numbers.end(), 
        [&](const auto& e) {
            return (e.value % 2) == 0;
        });

    int maxVal = 4;
    int result3 = std::count_if(numbers.begin(), numbers.end(),
        [&maxVal](const auto& e) {
            return (e.value > maxVal);
        });


    if (result != numbers.end()) {
        std::cout << "The first object with an even value is: " << result->value << std::endl;
    }
    else {
        std::cout << "No object with an even value found." << std::endl;
    }

    return 0;
}
