#include "HelperFunctions.h"
#include <iostream>
#include <fstream>
#include <filesystem>


using namespace std;

char* HelperFunctions::GetEnvVariable(std::string name)
{
	char* envariable;
	size_t bufferSize = 0;
	errno_t err = _dupenv_s(&envariable, &bufferSize, name.c_str());
	return envariable;
}

std::string HelperFunctions::GetFilePath()
{
	char* file = GetEnvVariable("INPUT_FILE");
	if (!file)
		file = "WrongFile.json";

	std::filesystem::path path = std::filesystem::current_path();
	std::string filepath = path.u8string() + "\\..\\..\\" + std::string(file);
	std::cout << "filepath = " << filepath.c_str() << std::endl;
	return filepath;

}


bool HelperFunctions::CanOpenFile()
{
	std::string filepath = GetFilePath();
	if (!std::filesystem::exists(filepath))
	{
		return false;
	}
	else
	{
		return true;
	}
}

std::tuple<int, int, std::string, std::vector<int>, std::string, int>
HelperFunctions::GetValuesFromJSON()
{
	using json = nlohmann::json;

	std::string filepath = GetFilePath();
	std::string empty = "";
	auto defaultTuple = std::make_tuple(0, 0, empty, std::vector<int>(), empty, 0);
	if (!std::filesystem::exists(filepath))
	{
		std::cout << "Could not find input file" << std::endl;
		return defaultTuple;
	}
	std::ifstream inputFile(filepath);

	json config;
	inputFile >> config;
	inputFile.close();
	//	// Access specific values from the JSON object
	int param1 = config["parameter1"];
	int param2 = config["parameter2"];
	std::string param3 = config["parameter3"];
	std::vector<int> param4 = config["parameter4"];
	std::string nested_param1 = config["parameter5"]["nested_param1"];
	int nested_param2 = config["parameter5"]["nested_param2"];

	return std::make_tuple(param1, param2, param3, param4, nested_param1, nested_param2);
}
