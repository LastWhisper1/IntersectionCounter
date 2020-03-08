#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <set>

using namespace std;

class Counter {
private:
	vector<Line*>* lineSet = new vector<Line*>();
	//unordered_set<Intersection, hash<Intersection>>* intersectionSet = new unordered_set<Intersection, hash<Intersection>>();
	set<Intersection>* intersectionSet = new set<Intersection>();
public:
	Counter();
	int CountIntersections();
	void addLine(Line* line);
};