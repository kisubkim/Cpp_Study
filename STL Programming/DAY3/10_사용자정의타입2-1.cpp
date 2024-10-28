#include <vector>
#include "show.h"


//^ 아주 중요한 내용임.

class Point
{
	int x, y;
public:
	Point(int a = 0, int b = 0) : x(a), y(b) 
	{
		std::cout << "Point()" << std::endl;
	}
	~Point() { std::cout << "~Point()" << std::endl; }
	
	Point(const Point& p)
	{
		std::cout << "Point(const Point&) - copy" << std::endl;
	}

	Point(Point&& p)
	{
		std::cout << "Point(Point&) - move" << std::endl;
	}
};
int main()
{
	std::vector<Point> v;

	// 실행결과 예측해 보세요
	// 1. 객체를 생성후 넣기.
	Point pt(1, 2);
	v.push_back(pt); 

	//? 순서 1. pt 생성자 -> vector 메모리할당 -> 할당된 memory에 pt copy(요때 생성자 호출) -> -----출력 -> 소멸자들 call(순서는 잘..)

	std::cout << "------------------" << std::endl;	

	// #2. 임시 객체 형태로 넣기.
	v.push_back(Point(1,2));		//& 임시 객체는 move 가 불림.
	std::cout << "------------------" << std::endl;	

	// #3. 임시 객체의 또다른 형태
	v.push_back({1,2});		//& 임시 객체는 move 가 불림.
	std::cout << "------------------" << std::endl;	
}



