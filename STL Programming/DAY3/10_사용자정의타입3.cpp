
#include <vector>
#include <algorithm>
#include "show.h"
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
};
int main()
{
	std::vector<Point> v;

	v.emplace_back(1, 2); // Point(1,2)
	v.emplace_back(2, 3);
	v.emplace_back(3, 2);
	v.emplace_back(0, 1);

	// 사용자 정의 ㅣ타입을 container 보관할 수 있지만
	// algorithm 사용 시에는 algorithm의 requirement를 충족해야함.
	// std::sort() 사용하기 위해서는 크기비료를 위한 cmp 가 있어야함.
	//std::sort(std::begin(v), std::end(v));		// error

	// #1. lambda 로 비교 정책전달
	std::sort(v.begin(), v.end(), 
			  [](const Point& p1, const Point& p2) {return p1.x < p2.x;});

	// #2. Point type 자체에 < 연산자 제공.
	// => 다음 예제 참고


}




