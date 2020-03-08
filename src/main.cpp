#include <iostream>
#include <fstream>
#include <math.h>
#include <map>
#include <set>
#include <algorithm>
#include "figure.h"
using namespace std;
Line l[10000];
Cycle c[10000];
map<Point, int>vis;
int N, ln, cn;
double eps = 1e-7;
int solveLine() {
	int ans = 0;
	sort(l, l + ln);
	map<Point, int>::iterator iter;
	for (int i = 0; i < ln; i++) {
		for (int j = 0; j < i; j++) {
			if (doublecompare(l[i].k, l[j].k) == 0) {
				break;
			}
			Point tpoint = l[i].intersectWithLine(l[j]);
			iter = vis.find(tpoint);
			if (iter == vis.end()) {
				ans += 1;
				vis[tpoint] = 1;
			}
		}
	}
	return ans;
}

int solveCycle() {
	int ans = 0;
	map<Point, int>::iterator iter;
	for (int i = 0; i < cn; i++) {
		for (int j = 0; j < ln; j++) {
			vector<Point> tpoint = c[i].intersectWithLine(l[j]);
			int nump = tpoint.size();
			for (int k = 0; k < nump; k++) {
				iter = vis.find(tpoint[k]);
				if (iter == vis.end()) {
					ans += 1;
					vis[tpoint[k]] = 1;
				}
			}
		}
		for (int j = 0; j < i; j++) {
			vector<Point> tpoint = c[i].intersectWithCycle(c[j]);
			int nump = tpoint.size();
			for (int k = 0; k < nump; k++) {
				iter = vis.find(tpoint[k]);
				if (iter == vis.end()) {
					ans += 1;
					vis[tpoint[k]] = 1;
				}
			}
		}
	}
	return ans;
}

int main(int argc, char** argv) {
	if (argc != 5) {
		return -1;
	}
	ifstream fin;
	ofstream fout;
	for (int i = 0; i < argc; i++) {
		if (strcmp(argv[i], "-i") == 0) {
			fin.open(argv[++i]);
		}
		if (strcmp(argv[i], "-o") == 0) {
			fout.open(argv[++i]);
		}
	}

	fin >> N;
	ln = 0;
	cn = 0;
	for (int i = 0; i < N; i++) {
		char op;
		fin >> op;
		switch (op) {
		case 'L':
			double x1, y1, x2, y2;
			fin >> x1 >> y1 >> x2 >> y2;
			l[ln++] = Line(x1, y1, x2, y2);
			break;
		case 'C':
			double x, y, r;
			fin >> x >> y >> r;
			c[cn++] = Cycle(x, y, r);
			break;
		default:
			return -1;
		}
	}
	int ans1 = solveLine();
	int ans2 = solveCycle();
	fin.close();
	fout << ans1 + ans2 << endl;
	fout.close();
}
