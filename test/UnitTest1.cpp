#include "pch.h"
#include "CppUnitTest.h"
#include "../IntersectionII/Line.h"
#include "../IntersectionII/Intersection.h"
#include "../IntersectionII/Counter.h"



using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTest1
{
	TEST_CLASS(IntersectionTest_Naive)
	{
	public:
		
		TEST_METHOD(TestMethod1)
		{
			Line* line1 = new Line(0, 4, 0, 8);
			Line* line2 = new Line(2, 3, 2, 6);
			Assert::IsTrue(line1->isParallel(line2));
		}
		TEST_METHOD(TestMethod2)
		{
			Line* line1 = new Line(0, 0, 0, 1);
			Line* line2 = new Line(0, 0, 1, 0);
			Line* line3 = new Line(0, 0, 1, 1);
			Line* line4 = new Line(0, 1, 1, 1);
			Counter* counter = new Counter();
			counter->addLine(line1);
			counter->addLine(line2);
			counter->addLine(line3);
			counter->addLine(line4);
			Assert::AreEqual(3, counter->CountIntersections());
		}
		TEST_METHOD(TestMethod3)
		{
			Line* line1 = new Line(-10, -9, -9, 10);
			Line* line2 = new Line(-9, 10, 10, 9);
			Line* line3 = new Line(10, 9, 9, -10);
			Line* line4 = new Line(9, -10, -10, -9);
			Counter* counter = new Counter();
			counter->addLine(line1);
			counter->addLine(line2);
			counter->addLine(line3);
			counter->addLine(line4);
			Assert::AreEqual(4, counter->CountIntersections());
		}
	};
	TEST_CLASS(IntersectionTest_Border)
	{
	public:
		TEST_METHOD(TestMethod1)
		{
			Line* line1 = new Line(-99999, 0, 99999, 1);
			Line* line2 = new Line(0, 0, 1, 0);
			Line* line3 = new Line(-99998, 0, -99998, 1);
			Counter* counter = new Counter();
			counter->addLine(line1);
			counter->addLine(line2);
			counter->addLine(line3);
			Assert::AreEqual(3, counter->CountIntersections());
		}
		TEST_METHOD(TestMethod2)
		{
			Line* line1 = new Line(-99999, 0, 99999, 1);
			Line* line2 = new Line(0, 0, 1, 0);
			Assert::IsFalse(line1->isParallel(line2));
		}
		TEST_METHOD(TestMethod3)
		{
			Line* line1 = new Line(0, 0, 99998, 2);
			Line* line2 = new Line(0, 2, 49999, 3);
			Assert::IsTrue(line1->isParallel(line2));
		}
		TEST_METHOD(TestMethod4)
		{
			Line* line1 = new Line(0, 0, 99998, 2);
			Line* line2 = new Line(0, 2, 49999, 3);
			Line* line3 = new Line(0, 0, -99999, 0);
			Counter* counter = new Counter();
			counter->addLine(line1);
			counter->addLine(line2);
			counter->addLine(line3);
			Assert::AreEqual(2, counter->CountIntersections());
		}
	};
}
