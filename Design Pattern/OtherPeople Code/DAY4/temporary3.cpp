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
	return Point(1, 2); // ��������� �ı��Ǿ�ߵǴµ�,
						// ������ �ı��� �� ����. pt�� ���Ͽ� �ӽð�ü�� ������ �ľ� ������
}

int main()
{
	Point ret = foo();
	std::cout << "==========================\n";
}
