#include "pch.h"
#include "CppUnitTest.h"
#include "D:/IntersectionCounter/src/Line.h"
#include "D:/IntersectionCounter/src/Intersection.h"
#include "D:/IntersectionCounter/src/Counter.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace IntersectionTest
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
	};
}
