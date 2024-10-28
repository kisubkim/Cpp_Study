// temporary1
#include <iostream>

class Point
{
	int x, y;
public:
	Point(int x, int y) : x(x), y(y) {}

	~Point() { std::cout << "~Point()" << x << " " << y << std::endl; }
};

int main()
{
	Point pt(1, 1); // 이름 있는 객.이름이 있으므로 다움줄도사용가능 수명은 블록을 벗어날 떄.
	Point (1, 2); // 이름 없는 객. ㅣㅇ름이 없으므로 다음문장에서 사용못함 세미콜론 만나면서 발오 팍외
	              // 잠깐 사용한다 해서 temporary object 로 부름

	std::cout << "------------\n";
}