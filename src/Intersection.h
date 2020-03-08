#pragma once
#include <iostream>
#include <string>
#include <vector>

//#define DOUBLE_MODE 0

using namespace std;

class Intersection
{
public:

#ifdef DOUBLE_MODE
	double x;
	double y;
#else
	int xnume; //x的分子
	int xdeno; //x的分母
	int ynume; //y的分子
	int ydeno; //y的分母
#endif //DOUBLE_MODE
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
#ifdef  DOUBLE_MODE
			return hash<double>()(s.x) + (hash<double>()(s.y) << 16);
#else
			return  hash<int>()(s.xnume * s.ydeno) +
				(hash<int>()(s.ynume * s.xdeno) << 16);
#endif //  DOUBLE_MODE
		}
	};
}