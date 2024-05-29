#include <iostream>
#include <regex>

using namespace std;

const char* CRITERIUM_GROUP = "Parent Issuer Sector";
int main()
{
	
	string fullString = string(CRITERIUM_GROUP) + "(field in brackets)";

	//regular expression string manipulation - easier to understand
	std::regex reg(CRITERIUM_GROUP + string("\\((.*)\\)"));
	string sectorName(regex_replace(fullString, reg, "$1"));
	cout << "Sector name with regex is: " << sectorName.c_str() << endl;

	//using find
	size_t startPos = fullString.find("(");
	size_t endPos = fullString.find(")");
	std::string sectorName2 = fullString.substr(startPos + 1, endPos - startPos - 1);
	std::cout << "Sector name with find is: " << sectorName2 << std::endl;

	//Both mehods return full string if no brackets found
	
}

