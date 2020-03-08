#include "figure.h"

Line::Line(int x1, int y1, int x2, int y2) {
	a = (double)y2 - y1;
	b = (double)x1 - x2;
	c = (double)x2 * y1 - (double)x1 * y2;
	if (b == 0) {
		k = 2000000;
	}
	else {
		k = -a / b;
	}
}

Cycle::Cycle(int ax, int ay, int ar) {
	x = ax;
	y = ay;
	r = ar;
}
