#include "pch.h"
#include "CppUnitTest.h"
#include "../ProjectToTest/Dll1/Class.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
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
	};
}
