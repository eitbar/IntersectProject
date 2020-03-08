#include "figure.h"
#include<vector>

bool Line::operator <(const Line& d) {
	return k < d.k;
}

Point Line::intersectWithLine(Line d) {
	double fm = a * d.b - b * d.a;
	double x = (b * d.c - c * d.b) / fm;
	double y = (d.a * c - a * d.c) / fm;
	return Point(x, y);
}

std::vector<Point> Cycle::intersectWithLine(Line t) {
	std::vector<Point>ps;
	double ld = abs(t.a * x + t.b * y + t.c) / sqrt(t.a * t.a + t.b * t.b);
	if (ld - r > 1e-6) {
		return ps;
	}
	else if (abs(ld - r) < 1e-6) {
		if (t.k == inf_k) {
			ps.push_back(Point(t.x1, y));
			return ps;
		}
		if (t.k == 0) {
			ps.push_back(Point(x, t.y1));
			return ps;
		}
		double b2 = x / t.k + y;
		double xt = t.k * (b2 - t.b) / (1 + t.k * t.k);
		double yt = t.k * xt + t.b;
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
	double xt = t.k * (b2 - t.b) / (1 + t.k * t.k);
	double yt = t.k * xt + t.b;
	double s1k2 = sqrt(1 + t.k * t.k);
	double nx = 1 / s1k2;
	double ny = t.k / s1k2;
	ps.push_back(Point(xt + ln * nx, yt + ln * ny));
	ps.push_back(Point(xt - ln * nx, yt - ln * ny));
	return ps;
}

std::vector<Point> Cycle::intersectWithCycle(Cycle t) {
	Line newl = Line(d - t.d, e - t.e, t.f - f);
	return intersectWithLine(newl);
}
