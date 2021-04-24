#include "pch.h"
#include "CppUnitTest.h"

#include "../Lab_5.2/main.cpp"


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestLab52
{
	TEST_CLASS(UnitTestLab52)
	{
	public:
		
		TEST_METHOD(TestMethod_SumGeomProgr) 
		{
			Assert::AreEqual(Sum_Geom_Progr1(4, -2, 6), -84.0);
		}
	};
}
