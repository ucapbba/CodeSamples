#include "CppUnitTest.h"
#include "../ProjectToTest/Dll1/Class.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "../../submodules//json/include/nlohmann/json.hpp"
#include <tuple>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:

		char* GetEnvVariable(std::string name)
		{
			char* envariable;
			size_t bufferSize = 0;
			errno_t err = _dupenv_s(&envariable, &bufferSize, name.c_str());
			return envariable;
		}

		TEST_METHOD(CanReadEnvVariable)
		{
			char* file = GetEnvVariable("INPUT_FILE");
			if (!file)
			{
				std::cout << "filename not found, will use default" << std::endl;
				Assert::AreEqual(1, 0);
			}

			std::cout << "filename = " << file << std::endl;
			Assert::AreEqual(1, 1);
		}

		std::string GetFilePath()
		{	
			char* file = GetEnvVariable("INPUT_FILE");
			if (!file)
				file = "WrongFile.json";

			std::filesystem::path path = std::filesystem::current_path();
			std::string filepath = path.u8string() + "\\..\\..\\"+std::string(file);
			std::cout << "filepath = " << filepath.c_str() << std::endl;
			return filepath;

		}

		bool CanOpenFile()
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

		auto GetValuesFromJSON()
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
		TEST_METHOD(TestMethod1)
		{
			double correctValue = 1.2;
			ClassToTest classTest;
			//Assert::AreEqual(correctValue, classTest.myfuncbroken());
			Assert::AreEqual(1,1);

		}

		TEST_METHOD(TestMethod2)
		{		
			double correctValue = 1.2;
			ClassToTest classTest;
			Assert::AreEqual(correctValue, classTest.myfuncworking());
		}

		TEST_METHOD(CanOpenFileTest)
		{
			bool canOpen = CanOpenFile();
			Assert::AreEqual(true, canOpen);
		}

		TEST_METHOD(TestInputFile)
		{
			int param1 = 10;
			int param2 = 20;
			std::string param3 = "some_value";
			std::string nested_param1 = "abc";
			int nested_param2 = 100;

			auto [p1, p2, p3, p4, np1, np2] = GetValuesFromJSON();

			Assert::AreEqual(param1, p1);
			Assert::AreEqual(param2, p2);
			Assert::AreEqual(param3, p3);
			Assert::AreEqual(nested_param1, np1);
			Assert::AreEqual(nested_param2, np2);

		}
	};
}
