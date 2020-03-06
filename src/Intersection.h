#pragma once
#include <iostream>
#include <string>

using namespace std;
class Intersection
{
public:
	int xnume; //x的分子
	int xdeno; //x的分母
	int ynume; //y的分子
	int ydeno; //y的分母
	Intersection(Line*, Line*);
	~Intersection();
private:
};