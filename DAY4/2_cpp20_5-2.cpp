#include <string>
#include <algorithm>
#include <functional>
#include <iostream>

struct Point {
	int x, y;

	int gety() const { return y; }	// 멤버 함수
};

int gety(const Point& p) { return p.y; } // 일반 단항 함수


//& 이 부분은 집에서 따로 시간내서 확인해 볼것. 아직 확실하게 이해 X 상태
template<>
struct std::less<Point> {
	bool operator()(const Point& p1, const Point& p2) {
		return p1.x > p2.x;
	}
};

int main() {

	Point p1{1,1};
	Point p2{2,2};

	//auto ret = std::ranges::max(p1, p2);		// error
	//auto ret2 = std::ranges::max(p1, p2, {}, &Point::gety);		// 멤버 함수 사용.
	//auto ret3 = std::ranges::max(p1, p2, {}, &gety);		// 일반 함수 사용.
	//auto ret4 = std::ranges::max(p1, p2, {}, &Point::y);		// 일반 함수 사용.

	std::cout << ret2 << std::endl;
	// Projection 에는
	// 1. public member data 의 address
	// 2. 인자가 없는 멤버 함수 주소
	// 3. 인자가 한개(p1, p2라면 인자가 Point인)인 일반 함수(객체), lambda

	return 0;
}