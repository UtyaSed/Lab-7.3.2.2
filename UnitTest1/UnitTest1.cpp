#include "pch.h"
#include "CppUnitTest.h"
#include "../PR 7.3.2.2/Source.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(UnitTest1)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			int a[3][3] = { { -1, 2, 3 },{ -4, 5, 6 },{ 7, 8, -9 } };
			int* pa[3] = { a[0], a[1], a[2] };
			int S = 0;

			S = Sum(pa, 3, 3, 0, 0);

			Assert::AreEqual(S, 16);
		}
	};
}
