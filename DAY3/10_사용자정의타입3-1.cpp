#include <vector>
#include <algorithm>
#include "show.h"

//using namespace std::rel_ops;		//& !=, <=, >=, >의 template version 제공 <-- 이거 c++17부터 못씀.

class Point
{
public:
	int x, y;

	Point(int a = 0, int b = 0) : x(a), y(b)
	{
		std::cout << "Point()" << std::endl;
	}
	~Point() { std::cout << "~Point()" << std::endl; }

	Point(const Point& p)
	{
		std::cout << "Point(const Point&)" << std::endl;
	}
	void dump() const 
	{
		std::cout << x << ", " << y << std::endl;
	}

	// 사용자 정의 타입의 비교를 위해서는 <, == 를 만들기를 권장.
	bool operator<(const Point& other) { return x < other.x; }
	bool operator==(const Point& other) { return x == other.x || y == other.y; }
};



template<typename T> bool operator !=(T a, T b)
{
	return !(a == b);
}
int main()
{
	Point p1(1,2);
	Point p2(2,3);

	bool b = p1 > p2;

	std::vector<Point> v;

	v.emplace_back(1, 2); // Point(1,2)
	v.emplace_back(2, 3);
	v.emplace_back(3, 2);
	v.emplace_back(0, 1);

	std::sort(v.begin(), v.end());


}




