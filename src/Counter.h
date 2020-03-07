#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

class Counter {
private:
	vector<Line*>* lineSet = new vector<Line*>();
	set<Intersection>* intersectionSet = new set<Intersection>();
public:
	Counter();
	int CountIntersections();
	void addLine(Line* line);
};