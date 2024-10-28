#include <iostream>

class Point {
	int x, y;
	public:
		Point(int a, int b) : x(a), y(b) { std::cout << "Point()\n"; }
		~Point() { std::cout << "~Point()\n"; }
};

int main()
{
	// heap에 object 1개 생성
	Point* p1 = new Point(1,2);

	// heap에 객체 10개 만들기
	//Point* p2 = new(operator new(sizeof(Point)*10)) Point(0,0);		// 내가 한거
	Point* p2 = static_cast<Point*>(operator new(sizeof(Point)*10));

	for(int i=0; i<10; i++){
		new(&p2[i]) Point(1,2);
	}

	for (int i=0; i<10; i++){
		p2[i].~Point();
	}

	
}
