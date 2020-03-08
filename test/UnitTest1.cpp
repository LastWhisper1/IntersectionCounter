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
			Line* line1 = new Line(2, 3, 3, 6);
			Assert::AreEqual(line1->ShowLine(), (string)"3x+-1y+-3=0");
		}
		TEST_METHOD(TestMethod2)
		{
			Line* line1 = new Line(0, 4, 0, 8);
			Line* line2 = new Line(2, 3, 2, 6);
			Assert::IsTrue(line1->isParallel(line2));
		}
		TEST_METHOD(TestMethod3)
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
		TEST_METHOD(TestMethod4)
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
		TEST_METHOD(TestMethod5)
		{
			Line* line1 = new Line(-100, -99, -99, 100);
			Line* line2 = new Line(-99, 100, 100, 99);
			Line* line3 = new Line(100, 99, 99, -100);
			Line* line4 = new Line(90, -100, -100, -99);
			Counter* counter = new Counter();
			counter->addLine(line1);
			counter->addLine(line2);
			counter->addLine(line3);
			counter->addLine(line4);
			Assert::AreEqual(5, counter->CountIntersections());
		}
		TEST_METHOD(TestMethod6)
		{
			Line* line1 = new Line(114, 514, 1919, 810);
			Counter* counter = new Counter();
			counter->addLine(line1);
			Assert::AreEqual(0, counter->CountIntersections());
		}
		TEST_METHOD(TestMethod7)
		{
			Line* line1 = new Line(0, 1, 4, 2);
			Line* line2 = new Line(7, 6, 9, 0);
			Intersection* insec = new Intersection(line1, line2);
			Assert::AreEqual(insec->xnume / insec->xdeno, 8);
			Assert::AreEqual(insec->ynume / insec->ydeno, 3);
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
		TEST_METHOD(TestMethod5)
		{
			Line* line1 = new Line(0, 0, 1, 1);
			Line* line2 = new Line(1, 0, 0, 1);
			Line* line3 = new Line(1, 2, 2, 0);
			Line* line4 = new Line(0, 3, 1, 2);
			Line* line5 = new Line(0, 1, 2, 2);
			Counter* counter = new Counter();
			counter->addLine(line1);
			counter->addLine(line2);
			counter->addLine(line3);
			counter->addLine(line4);
			counter->addLine(line5);
			Assert::AreEqual(9, counter->CountIntersections());
		}
	};
}
