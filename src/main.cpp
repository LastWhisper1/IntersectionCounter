#include <iostream>
#include <string>
#include "Line.h"
#include "Intersection.h"
#define A1 (line1->A)
#define B1 (line1->B)
#define C1 (line1->C)
#define A2 (line2->A)
#define B2 (line2->B)
#define C2 (line2->C)
using namespace std;

Line::Line(int x1, int y1, int x2, int y2)
{
	if (x1 == x2) {
		//x + C = 0
		A = 1;
		B = 0;
		C = - x1;
	}
	else if (y1 == y2) {
		//y + C = 0
		A = 0;
		B = 1;
		C = -y1;
	}
	else {
		A = y2 - y1;
		B = x1 - x2;
		C = y1 * x2 - y2 * x1;
	}
}

Line::~Line()
{
}

void Line::ShowLine() {
	cout << to_string(A) + "x+" + to_string(B) + "y+" + to_string(C) + "=0" << endl;
}

Intersection::Intersection(Line* line1, Line* line2) {
	xnume = C1 * B2 - C2 * B1;
	xdeno = B1 * A2 - B2 * A1;
	ynume = A1 * C2 - A2 * C1;
	ydeno = xdeno;
}

Intersection::~Intersection() 
{
}

int main(char argc, char** argv) {
	int n;
	string op;
	int x1, y1, x2, y2;
	cin >> n;
	while (n--) {
		cin >> op >> x1 >> y1 >> x2 >> y2;
		if (op == "L") {
			Line* line = new Line(x1, y1, x2, y2);
			line->ShowLine();
			delete line;
		}
	}
	cout << 1/(1e7+1)-1/(1e7) << endl;
}