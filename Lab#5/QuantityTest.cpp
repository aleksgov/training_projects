#include "pch.h"
#include "CppUnitTest.h"
#include "../labarotornya5/Quantity.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace QuantityTest
{
	TEST_CLASS(QuantityTest)
	{
	public:
		TEST_METHOD(ConstructTest)
		{
			 QuantityOfInformation val2;
			Assert::IsTrue(val2.get_bytes() == 100000);
		}
	};
}
