#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>
#include "Line.h"
#include "Intersection.h"
#include "Counter.h"

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

string Line::ShowLine() {
	return to_string(A) + "x+" + to_string(B) + "y+" + to_string(C) + "=0";
}

inline bool Line::isParallel(Line* lineb) {
	return (A * lineb->B == B * lineb->A);
}

Intersection::Intersection(Line* line1, Line* line2) {
#ifdef DOUBLE_MODE
	int xnume = C1 * B2 - C2 * B1;
	int xdeno = B1 * A2 - B2 * A1;
	int ynume = A1 * C2 - A2 * C1;
	int ydeno = xdeno;
	x = (double)xnume / xdeno;
	y = (double)ynume / ydeno;
#else
	xnume = C1 * B2 - C2 * B1;
	xdeno = B1 * A2 - B2 * A1;
	ynume = A1 * C2 - A2 * C1;
	ydeno = xdeno;
#endif //DOUBLE_MODE
}

bool Intersection::operator ==(const Intersection& intsec2) const {
#ifdef DOUBLE_MODE
	return x == intsec2.x && y == intsec2.y;
#else
	return (xnume * intsec2.xdeno == intsec2.xnume * xdeno
		&& ynume * intsec2.ydeno == intsec2.ynume * ydeno);
#endif // DOUBLE_MODE
}

bool Intersection::operator <(const Intersection& intsec2) const {
#ifdef DOUBLE_MODE
	return x < intsec2.x || (x == intsec2.x && y < intsec2.y);
#else
	return (xnume * intsec2.xdeno < intsec2.xnume * xdeno
		|| (xnume * intsec2.xdeno == intsec2.xnume * xdeno
			&& ynume * intsec2.ydeno < intsec2.ynume * ydeno));
#endif // DOUBLE_MODE
}

bool Intersection::operator >(const Intersection& intsec2) const {
#ifdef DOUBLE_MODE
	return x > intsec2.x || (x == intsec2.x && y > intsec2.y);
#else
	return (xnume * intsec2.xdeno > intsec2.xnume * xdeno
		|| (xnume * intsec2.xdeno == intsec2.xnume * xdeno
			&& ynume * intsec2.ydeno > intsec2.ynume * ydeno));
#endif // DOUBLE_MODE
}

Intersection::~Intersection() 
{
}

Counter::Counter() {}

inline void Counter::addLine(Line* line) {
	lineSet->push_back(line);
}

int Counter::CountIntersections() {
	for (size_t i = 0; i < lineSet->size(); i++) {
		Line* line1 = lineSet->at(i);
		for (size_t j = 0; j < i; j++) {
			Line* line2 = lineSet->at(j);
			if (!line1->isParallel(line2)) {
				Intersection intsec(line1, line2);
				intersectionSet->insert(intsec);
			}
		}
	}
	return intersectionSet->size();
}

int main(int argc, char** argv) {
	int count = 0;
	ifstream infile;
	ofstream outfile;
	while (count < argc) {
		if ((string)argv[count] == "-i") {
			infile.open(argv[count + 1]);
		}
		else if ((string)argv[count] == "-o") {
			outfile.open(argv[count + 1]);
		}
		count++;
	}
	Counter* counter = new Counter();
	int n;
	string op;
	int x1, y1, x2, y2;
	infile >> n;
	cout << n << endl;
	int A[10] = { 0 };
	while (n--) {
		infile >> op >> x1 >> y1 >> x2 >> y2;
		if (op == "L") {
			Line* line = new Line(x1, y1, x2, y2);
			//line->ShowLine();
			counter->addLine(line);
		}
	}
	infile.close();
	int ans;
	ans = counter->CountIntersections();
	cout << ans << endl;
	outfile << ans << endl;
	delete counter;
	outfile.close();
}