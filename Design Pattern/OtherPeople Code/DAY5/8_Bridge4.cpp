// Point.h
class Point
{
	int x, y;
	int debug;
public:
	void print();
};
// Point.cpp
#include "Point.h"

void Point::print() { } // ���� ����

// sjsqkqh.h
#include "Point.h"

class sjsqkqh : public Point
{
	using Point::Point;
};

// main.cpp
#include "sjsqkqh.h"
int main()
{
	sjsqkqh p;
	p.print();
}


