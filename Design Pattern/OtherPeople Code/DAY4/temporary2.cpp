// temporary1
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	~Point() { std::cout << "~Point()\n"; }
};

void draw_pixel(int a, int b) {}

void draw_line(const Point& from, const Point& to) {}

int main()
{
	// 1, 2 에 점을 그리고 싶다. 좋은 코드는 ?

	int x = 1, y = 2;	// 1. 변수를 만들어서
	draw_pixel(x, y);	//    함수에 전달하자!

	draw_pixel(1, 2);   // 2. 값이 정해졌으므로 literal 을 보내자.

	// 당연히 "2"가 좋습니다.


	// (1,2) ~ (3, 4) 에 선을 그리고 싶다.
	Point p1(1, 2);
	Point p2(3, 4);

	draw_line(p1, p2); // ?? 어떨까요 ? 평가해 보세요
	// p1, p2 는 함수 호출뒤에서 계속 남아 있습니다.
	// 이름이 있으므로

// 함수 인자로만 사용할 객체는 "temporary" 형태로 전달하는 것이 좋습니다.
	draw_line(Point(1, 2), Point(3, 4));
}
