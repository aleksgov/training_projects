#include "pch.h"
#include "CppUnitTest.h"
#include "../laba6/Pill.h"
#include <iostream>
#include <sstream>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest
{
	TEST_CLASS(UnitTest)
	{
	public:
		
		TEST_METHOD(TestCost)
		{
			Pills test("test", 1000, "test");
			std::stringstream input("5");
			std::streambuf* oldInput = std::cin.rdbuf(input.rdbuf());
			test.setter();
			std::cin.rdbuf(oldInput);
			Assert::IsTrue(test.cost() == 5000);
		}
		TEST_METHOD(TestPrice)
		{
			Pills test("test", 1000, "test");
			Assert::IsTrue(test.get_price() == 1000);
		}
		TEST_METHOD(TestNumSet)
		{
			Pills test;
			std::stringstream input("10");
			std::streambuf* oldInput = std::cin.rdbuf(input.rdbuf());
			test.setter();
			std::cin.rdbuf(oldInput);
			Assert::IsTrue(test.get_num() == 10);
		}
	};
}
