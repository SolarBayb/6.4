#include "pch.h"
#include "CppUnitTest.h"
#include "../6.4/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTes
{
	TEST_CLASS(UnitTes)
	{
	public:

		TEST_METHOD(TestMethod1)
		{
			double _sum;
			double a[] = { -1, -2,3,4 };
			_sum = sum(a, 4);
			Assert::AreEqual(_sum, 7.);
		}
	};
}