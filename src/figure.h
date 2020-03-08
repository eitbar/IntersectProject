#pragma once
#include<math.h>
#include<vector>
#define inf_k 2000000

class Point {
public:
	double x;
	double y;
	Point* next;
	Point(double xx, double yy) {
		x = xx;
		y = yy;
		next = 0;
	}
	bool operator <(const Point& d) const {
		if (fabs(x - d.x) < 1e-6) {
			return y < d.y;
		}
		return x < d.x;
	}

	bool operator ==(const Point& d) const {
		if (fabs(x - d.x) < 1e-6 && fabs(y - d.y) < 1e-6) {
			return true;
		}
		return false;
	}
};

class Line {
public:
	double x1, y1;
	//ax+by+c=0
	double a, b, c;
	//k=-a/b
	double k;
	Line() {
		a = b = c = k = 0;
		x1 = y1 = 0;
	}
	Line(double a1, double b1, double c1) {
		a = a1;
		b = b1;
		c = c1;
		if (b1 == 0) {
			x1 = -c1 / a1;
			y1 = 1;
			k = inf_k;
		}
		else {
			x1 = 1;
			y1 = (-c - a) / b;
			k = -a / b;
		}

	}
	Line(int x11, int y11, int x21, int y21) {
		x1 = x11;
		y1 = y11;
		a = (double)y21 - y11;
		b = (double)x11 - x21;
		c = (double)x21 * y11 - (double)x11 * y21;

		if (b == 0) {
			k = inf_k;
		}
		else {
			k = -a / b;
		}
	}
	bool operator <(const Line& d);
	Point intersectWithLine(Line d);
};

class Cycle
{
public:
	double x, y, r;
	double d, e, f;
	Cycle() {
		x = y = r = 0;
		d = e = f = 0;
	}
	Cycle(double ax, double ay, double ar) {
		x = ax;
		y = ay;
		r = ar;
		d = -2 * ax;
		e = -2 * ay;
		f = ax * ax + ay * ay - ar * ar;
	}

	std::vector<Point> intersectWithLine(Line t);

	std::vector<Point> intersectWithCycle(Cycle t);
};
