#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Intersection
{
public:
	int xnume; //x的分子
	int xdeno; //x的分母
	int ynume; //y的分子
	int ydeno; //y的分母
	Intersection(Line*, Line*);
	bool operator ==(const Intersection&) const; //重载运算符==，用于分式相等判定
	bool operator >(const Intersection&) const;
	bool operator <(const Intersection&) const;
	~Intersection();
private:
};

namespace std
{
	template<>
	struct hash<Intersection>
	{
		size_t operator() (const Intersection& s) const noexcept
		{
			return  hash<decltype(s.xdeno)>()(s.xnume) +
				hash<decltype(s.ydeno)>()(s.ynume);
		}
	}; // 间接调用原生Hash.
}