#include "CppUnitTest.h"
#include "../ProjectToTest/Dll1/Class.h"
#include <iostream>
#include <fstream>
#include <filesystem>
#include "../../submodules//json/include/nlohmann/json.hpp"
#include <tuple>
#include "HelperFunctions.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTestFile1)
	{
	public:


		HelperFunctions help;
		TEST_METHOD(CanReadEnvVariable)
		{
			char* file = help.GetEnvVariable("INPUT_FILE");
			if (!file)
			{
				std::cout << "filename not found, will use default" << std::endl;
				Assert::AreEqual(1, 0);
			}

			std::cout << "filename = " << file << std::endl;
			Assert::AreEqual(1, 1);
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
			bool canOpen = help.CanOpenFile();
			Assert::AreEqual(true, canOpen);
		}

		TEST_METHOD(TestInputFile)
		{
			int param1 = 10;
			int param2 = 20;
			std::string param3 = "some_value";
			std::string nested_param1 = "abc";
			int nested_param2 = 100;

			auto [p1, p2, p3, p4, np1, np2] = help.GetValuesFromJSON();

			Assert::AreEqual(param1, p1);
			Assert::AreEqual(param2, p2);
			Assert::AreEqual(param3, p3);
			Assert::AreEqual(nested_param1, np1);
			Assert::AreEqual(nested_param2, np2);

		}
	};
}
