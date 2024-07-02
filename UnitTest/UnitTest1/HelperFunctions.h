#ifndef __HELPER_FUNCS__
#define __HELPER_FUNCS__
#include <nlohmann/json.hpp>
#include <tuple>
#include <vector>
using json = nlohmann::json;

class HelperFunctions
{
	public:
		char* GetEnvVariable(std::string name);
		std::string GetFilePath();
		bool CanOpenFile();
		std::tuple<int, int, std::string, std::vector<int>, std::string, int> GetValuesFromJSON();
};

#endif