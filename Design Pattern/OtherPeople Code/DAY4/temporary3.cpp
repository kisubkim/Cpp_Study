// temporary1
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	~Point() { std::cout << "~Point()\n"; }
};

Point foo() {
	return Point(1, 2); // 원래라면은 파괴되어야되는데,
						// 실제로 파괴된 게 맞음. pt는 리턴용 임시객체를 복사한 후애 삭제됨
}

int main()
{
	Point ret = foo();
	std::cout << "==========================\n";
}
