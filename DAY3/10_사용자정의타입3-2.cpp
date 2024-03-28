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

	//& compiler에게 <=> 연산자 구현을 요청.
	auto operator<=>(const Point& other) const = default;

};



// template<typename T> bool operator !=(T a, T b)
// {
// 	return !(a == b);
// }
int main()
{
	// c++20의 새로운 연산자 ( three way comparison, "우주선연산자" 라는 별명
	auto ret = 1 <=> 3; // a <=> b
						// a가 크면 ret > 0
						// b가 크면 ret < 0
						// a==b     ret == 0

	//std::cout << ret << std::endl;
	Point p1(1,2);
	Point p2(2,3);

	bool b = p1 > p2;		// (p1 <=> p2) > 0
	bool b2 = p1 < p2;		// (p1 <=> p2) < 0
	bool b3 = p1 == p2;		// (p1 <=> p2) == 0
	//^ 이렇게 하면 무조건 x 먼저 검사함.
	//^ 하지만 x가 같으면 y를 검사함.
	//^ 즉, 변수 선언 순서가 검사 순서임.

	std::cout << b << std::endl;

}

//& c++20 rewrite code 사용 가능.




