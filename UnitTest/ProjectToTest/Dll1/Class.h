#pragma once
/**
 * Detailed information.......
 * 
 * 
 * 
 * more detailed info........
 * 
 * 
 * 
 * etc.........
 * @brief ClassToTest used for unit testing.  

 */
class ClassToTest
{  

private:

    /**
    * @brief Sample function for doxygen documentation
    * @param a some variable passed to the function 
    * @return returns the variable 1
    *
    */
    double myWellDocumentedFucntion(double a) { return a; }

public:
    /**
    * Create a new ClassToTest object .
    * @brief Default constructor.
    * @see myWellDocumentedFucntion(double a)
    * @see myfuncworking()
    * @see myfuncbroken()
    */
    ClassToTest() {};
    /**
    * @brief Function for working unit test
    * @return returns a double
    */
	double myfuncworking() { return 1.2; }
    /**
    * @brief Originally a function for the failing unit test
    * @return returns a double
    */
	double myfuncbroken() { return 1.3; }
};

