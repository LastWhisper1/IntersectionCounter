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
	int xnume; //x�ķ���
	int xdeno; //x�ķ�ĸ
	int ynume; //y�ķ���
	int ydeno; //y�ķ�ĸ
#endif //DOUBLE_MODE
	Intersection(Line*, Line*);
	bool operator ==(const Intersection&) const; //���������==�����ڷ�ʽ����ж�
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