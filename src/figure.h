#pragma once

class Line {
public:
	//ax+by+c=0
	double a, b, c;
	//k=-a/b
	double k;

	Line(int x1, int y1, int x2, int y2);

};

class Cycle
{
public:
	int x, y, r;

	Cycle(int x, int y, int r);
};
