#include <iostream>

class Point {
	int x, y;
	public:
		Point(int a, int b) : x(a), y(b) { std::cout << "Point()\n"; }
		~Point() { std::cout << "~Point()\n"; }
};

int main()
{
	Point* p1 = new Point(1,2);		// 1. memory alloc, 2. constructor call
	delete p1;						// 1. destroyer call, 2. memory free

	Point* p2 = (Point*)operator new(sizeof(Point));		//^ memory만 할당. malloc 이랑 동일.
						//^ operator new 라는 함수가 있음. (c++ 에서 제공)

	new(p2) Point(1,1);		// 생성자 호출
	
	p2->~Point();
	operator delete(p2);		//^ 메모리만 해지. free 랑 동일.

	return 0;
}

//& new는 메모리 할당 연산자가 아님. 객체를 생성하는 연산자임.
//& malloc : memory allocation
//& new : object create (memory create + constructor call)
//? new Point(1,2)		// 새로운 메모리에 객체를 생성
//? new(p) Point(1,2)	// 이미 할당된 메모리(p)에 객체를 생성해 달라. ==> 생성자만 호출.