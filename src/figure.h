﻿#pragma once
#include<math.h>
#include <unordered_map>
#include<vector>
#define inf_k 2000000
using namespace std;
int doublecompare(double x, double y);

class Point {
public:
	double x;
	double y;

	Point(double xx, double yy) {
		x = xx;
		y = yy;
	}
	bool operator <(const Point& d) const {
		if (doublecompare(x, d.x) == 0) {
			return y < d.y;
		}
		return x < d.x;
	}

	bool operator ==(const Point& d) const {
		if (doublecompare(x, d.x) == 0 && doublecompare(y, d.y) == 0) {
			return true;
		}
		return false;
	}
};

class PointHash
{
public:
	std::size_t operator()(const Point& c) const
	{
		return hash<double>()(c.x) + (hash<double>()(c.y) << 16);
	}
};

class Line {
public:
	double x1, y1;
	//ax+by+c=0
	double a, b, c;
	//y=kx+b1
	double k, b1;
	Line() {
		a = b = c = k = b1 = 0;
		x1 = y1 = 0;
	}
	Line(double aa, double bb, double cc) {
		a = aa;
		b = bb;
		c = cc;
		if (bb == 0) {
			x1 = -cc / aa;
			y1 = 1;
			k = inf_k;
			b1 = inf_k;
		}
		else {
			x1 = 1;
			y1 = (-c - a) / b;
			k = -a / b;
			b1 = -c / b;
		}

	}
	Line(double x11, double y11, double x21, double y21) {
		x1 = x11;
		y1 = y11;
		a = y21 - y11;
		b = x11 - x21;
		c = x21 * y11 - x11 * y21;

		if (b == 0) {
			k = inf_k;
			b1 = inf_k;
		}
		else {
			k = -a / b;
			b1 = -c / b;
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
