#include <iostream>
#include <vector>
class Point {
	int x, y;
	public:
		Point(int a, int b) : x(a), y(b) { std::cout << "Point()\n"; }
		~Point() { std::cout << "~Point()\n"; }
};

int main()
{
	//std::vector<Point> v = {{1,1}, {2,2}, {3,3}};
	std::vector<Point> v(5, Point(0,0));	// 5개를 Point(0,0) 으로 
	std::cout << "-----------------------------------\n";
	v.resize(2, Point(0,0));		// 메모리 제거 안됨 //& 내부에 들어있는 객체의 소멸자는 호출함.

	std::cout << "-----------------------------------\n";
	v.push_back(Point{4,4});		//* 메모리는 이미 있음.
									//* 해당 메모리에 대해 생성자를 호출.
	std::cout << "-----------------------------------\n";
}
