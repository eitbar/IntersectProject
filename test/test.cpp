#include "pch.h"
#include "CppUnitTest.h"
#include "../IntersectProject/src/figure.h"
#include<vector>
#include<math.h>
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test
{
	TEST_CLASS(test)
	{
	public:

		TEST_METHOD(TestDoubleCompare)
		{
			Assert::AreEqual(0, doublecompare(0.000000001, 0));
			Assert::AreEqual(1, doublecompare(0.0000001, 0));
			Assert::AreEqual(-1, doublecompare(0, 0.0000001));
		}

		TEST_METHOD(TestLInL)
		{
			Line l1 = Line(-100000, -1, 100000, 1);
			Line l2 = Line(-100000, 1, 100000, -1);
			Assert::AreEqual(true, Point(0, 0) == l1.intersectWithLine(l2));
			l1 = Line(100000, 100000, 0, -100000);
			l2 = Line(2, -100000, 99999, 100000);
			Assert::AreEqual(true,
				Point(66666.6666666666, 33333.333333333) == l1.intersectWithLine(l2));
			l1 = Line(0, 0, 1, 1);
			l2 = Line(0, 1, 1, 0);
			Assert::AreEqual(true, Point(0.5, 0.5) == l1.intersectWithLine(l2));
			Assert::AreEqual(true, Point(0.5, 0.5) == l2.intersectWithLine(l1));
			l1 = Line(0, 0, 1, 1);
			l2 = Line(3, 0, 3, 2);
			Assert::AreEqual(true, Point(3, 3) == l1.intersectWithLine(l2));
			Assert::AreEqual(true, Point(3, 3) == l2.intersectWithLine(l1));
			l1 = Line(0, 0, 1, 1);
			l2 = Line(0, 3, 1, 3);
			Assert::AreEqual(true, Point(3, 3) == l1.intersectWithLine(l2));
			Assert::AreEqual(true, Point(3, 3) == l2.intersectWithLine(l1));

			l1 = Line(0, 0, 1, 1);
			l2 = Line(1, 0, 2, 1);
			Assert::AreEqual(true, Point(inf_k, inf_k) == l2.intersectWithLine(l1));

			l1 = Line(1, 1, 1, 2);
			l2 = Line(1, 1, -1, 1);

			Cycle c1 = Cycle(0, 0, 1);
			std::vector<Point>p = c1.intersectWithLine(l1);
			Assert::AreEqual(1, (int)p.size());
			Assert::AreEqual(true, Point(1, 0) == p[0]);

			p = c1.intersectWithLine(l2);
			Assert::AreEqual(1, (int)p.size());
			Assert::AreEqual(true, Point(0, 1) == p[0]);


			c1 = Cycle(0, 0, 2);
			p = c1.intersectWithLine(l1);
			Assert::AreEqual(2, (int)p.size());
			Assert::AreEqual(true, Point(1, sqrt(3)) == p[1]);
			Assert::AreEqual(true, Point(1, -sqrt(3)) == p[0]);

			p = c1.intersectWithLine(l2);
			Assert::AreEqual(2, (int)p.size());
			Assert::AreEqual(true, Point(sqrt(3), 1) == p[1]);
			Assert::AreEqual(true, Point(-sqrt(3), 1) == p[0]);

			c1 = Cycle(1, 1, 2);
			p = c1.intersectWithLine(l1);
			Assert::AreEqual(2, (int)p.size());
			Assert::AreEqual(true, Point(1, 3) == p[1]);
			Assert::AreEqual(true, Point(1, -1) == p[0]);

			p = c1.intersectWithLine(l2);
			Assert::AreEqual(2, (int)p.size());
			Assert::AreEqual(true, Point(3, 1) == p[1]);
			Assert::AreEqual(true, Point(-1, 1) == p[0]);

			c1 = Cycle(10, 10, 1);
			p = c1.intersectWithLine(l2);
			Assert::AreEqual(0, (int)p.size());

			c1 = Cycle(0, 0, 2);
			Cycle c2 = Cycle(0, 0, 1);
			p = c1.intersectWithCycle(c2);
			Assert::AreEqual(0, (int)p.size());

			c2 = Cycle(0, 0, 3);
			p = c1.intersectWithCycle(c2);
			Assert::AreEqual(0, (int)p.size());

			c2 = Cycle(1, 0, 1);
			p = c1.intersectWithCycle(c2);
			Assert::AreEqual(1, (int)p.size());
			Assert::AreEqual(true, Point(2, 0) == p[0]);

			c2 = Cycle(3, 0, 1);
			p = c1.intersectWithCycle(c2);
			Assert::AreEqual(1, (int)p.size());
			Assert::AreEqual(true, Point(2, 0) == p[0]);

			c2 = Cycle(2, 0, 2);
			p = c1.intersectWithCycle(c2);
			Assert::AreEqual(2, (int)p.size());
			Assert::AreEqual(true, Point(1, sqrt(3)) == p[1]);
			Assert::AreEqual(true, Point(1, -sqrt(3)) == p[0]);

			c2 = Cycle(10, 10, 2);
			p = c1.intersectWithCycle(c2);
			Assert::AreEqual(0, (int)p.size());
		}
	};
}
