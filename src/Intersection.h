#pragma once
#include <iostream>
#include <string>

using namespace std;
class Intersection
{
public:
	int xnume; //x�ķ���
	int xdeno; //x�ķ�ĸ
	int ynume; //y�ķ���
	int ydeno; //y�ķ�ĸ
	Intersection(Line*, Line*);
	~Intersection();
private:
};