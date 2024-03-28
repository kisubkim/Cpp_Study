#include <vector>
#include "show.h"

// 

class Point
{
	int x, y;
public:
	Point(int a, int b) : x(a), y(b) {}
};
int main()
{
	// #1. default constructor 없는 type
	//std::vector<Point> v(10); 	// error
	std::vector<Point> v(10, Point(0,0));	// ok

	//v.resize(20); // error
	v.resize(20, Point(0,0));	// ok.
	
}

// c++ Idioms 에서 "generic container idioms 참고"
// => container 만들 때는 저장하는 element에 대해서 최소한의 rquirement 를 가져야함.
//& STL container는 '복사 생성자', '그어떤 상황에서도 예외가 없는 소멸자' 가 있으면 저장 가능.
//


