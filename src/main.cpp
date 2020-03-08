#include <iostream>
#include <fstream>
#include "figure.h"
using namespace std;
Line* l[10000];
Cycle* c[10000];
int main(int argc, char** argv)
{
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
	int N; char op;
	fin >> N;
	int ln = 0;
	int cn = 0;
	for (int i = 0; i < N; i++) {
		fin >> op;
		switch (op) {
		case 'L':
			int x1, y1, x2, y2;
			fin >> x1 >> y1 >> x2 >> y2;
			l[ln++] = new Line(x1, y1, x2, y2);
			break;
		case 'C':
			int x, y, r;
			fin >> x >> y >> r;
			c[cn++] = new Cycle(x, y, r);
			break;
		default:
			return -1;
		}
	}
	fin.close();
	fout << ln << " " << cn << endl;
	fout.close();
}
