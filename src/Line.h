#pragma once
#include <iostream>
#include <string>

using namespace std;

class Line
{
public:
	//use Ax + By + C = 0 to describe each line
	int A;
	int B;
	int C;
	Line(int, int, int, int);
	~Line();
	bool isParallel(Line*);
	void ShowLine();
private:

};
