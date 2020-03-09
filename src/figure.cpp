#include "figure.h"
#include<iostream>
#include<vector>
using namespace std;

int doublecompare(double x, double y) {
	if (fabs(x - y) < 1e-8) {
		return 0;
	}
	else if (x - y > 1e-8) {
		return 1;
	}
	else {
		return -1;
	}
}

bool Line::operator <(const Line& d) {
	return k < d.k;
}

Point Line::intersectWithLine(Line d) {
	double fm = a * d.b - b * d.a;
	if (fm == 0) {
		return Point(inf_k, inf_k);
	}
	double x = (b * d.c - c * d.b) / fm;
	double y = (d.a * c - a * d.c) / fm;
	return Point(x, y);
}

std::vector<Point> Cycle::intersectWithLine(Line t) {
	std::vector<Point>ps;
	double ld = abs(t.a * x + t.b * y + t.c) / sqrt(t.a * t.a + t.b * t.b);
	if (doublecompare(ld, r) == 1) {
		return ps;
	}
	else if (doublecompare(ld, r) == 0) {
		if (t.k == inf_k) {
			ps.push_back(Point(t.x1, y));
			return ps;
		}
		if (t.k == 0) {
			ps.push_back(Point(x, t.y1));
			return ps;
		}
		double b2 = x / t.k + y;
		double b1 = -t.c / t.b;
		double xt = t.k * (b2 - b1) / (1 + t.k * t.k);
		double yt = t.k * xt + b1;
		ps.push_back(Point(xt, yt));
		return ps;
	}
	double ln = sqrt(r * r - ld * ld);
	if (t.k == inf_k) {
		ps.push_back(Point(t.x1, y - ln));
		ps.push_back(Point(t.x1, y + ln));
		return ps;
	}
	if (t.k == 0) {
		ps.push_back(Point(x - ln, t.y1));
		ps.push_back(Point(x + ln, t.y1));
		return ps;
	}
	double b2 = x / t.k + y;
	double b1 = -t.c / t.b;
	double xt = t.k * (b2 - b1) / (1 + t.k * t.k);
	double yt = t.k * xt + b1;
	double s1k2 = sqrt(1 + t.k * t.k);
	double nx = 1 / s1k2;
	double ny = t.k / s1k2;
	ps.push_back(Point(xt + ln * nx, yt + ln * ny));
	ps.push_back(Point(xt - ln * nx, yt - ln * ny));
	return ps;
}

std::vector<Point> Cycle::intersectWithCycle(Cycle t) {
	vector<Point> p;
	double rd = sqrt((t.x - x) * (t.x - x) + (t.y - y) * (t.y - y));
	double rr = r + t.r;
	if (doublecompare(rd, rr) > 0 || doublecompare(rd + t.r, r) < 0) {
		return p;
	}
	Line newl = Line(d - t.d, e - t.e, f - t.f);
	return intersectWithLine(newl);
}
