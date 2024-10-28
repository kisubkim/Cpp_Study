#include <vector>
#include "show.h"


//^ 아주 중요한 내용임.
//& 사용자 정의 타입을 보관한다면 "push_xxxx" 대신에 "emplace_xxx" 사용
//& push_back -> emplace_back
//& push_front -> emplace_back
//& insert -> emplace
//^ 단, primitive or usertype* 인 경웨는 push_xxx, emplace_xxx 모두 비슷

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

	std::cout << "------------------ size : " << v.size() << std::endl;	

	// #2. 임시 객체 형태로 넣기.
	v.push_back(Point(1,2));		//& 임시 객체는 move 가 불림.
	std::cout << "------------------ size : " << v.size() << std::endl;	

	// #3. 임시 객체의 또다른 형태
	v.push_back({1,2});		//& 임시 객체는 move 가 불림.
	std::cout << "------------------ size : " << v.size() << std::endl;	

	//* #4. 객체를 전달하지 말고, 객체를 만들기 위한 인자만 전달. --> emplace
	v.emplace_back(1,2);
	std::cout << "------------------ size : " << v.size() << std::endl;	
}



