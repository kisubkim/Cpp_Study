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
	Point pt(1, 1); // �̸� �ִ� ��.�̸��� �����Ƿ� �ٿ��ٵ���밡�� ������ ����� ��� ��.
	Point (1, 2); // �̸� ���� ��. �Ӥ����� �����Ƿ� �������忡�� ������ �����ݷ� �����鼭 �߿� �ſ�
	              // ��� ����Ѵ� �ؼ� temporary object �� �θ�

	std::cout << "------------\n";
}