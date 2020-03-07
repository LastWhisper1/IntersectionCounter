#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Intersection
{
public:
	int xnume; //x�ķ���
	int xdeno; //x�ķ�ĸ
	int ynume; //y�ķ���
	int ydeno; //y�ķ�ĸ
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
			return  hash<decltype(s.xdeno)>()(s.xnume) +
				hash<decltype(s.ydeno)>()(s.ynume);
		}
	}; // ��ӵ���ԭ��Hash.
}