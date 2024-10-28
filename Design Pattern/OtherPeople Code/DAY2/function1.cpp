// function1.cpp
#include <iostream>
#include <functional>	// std::bind() �� ������� �ֽ��ϴ�.
using namespace std::placeholders; // _1, _2, _3 ...

void foo(int a, int b, int c, int d)
{
	printf("%d, %d, %d, %d\n", a, b, c, d);
}

class Sample
{
public:
	void goo(int a, int b) {}
};

int main()
{
	foo(1, 2, 3, 4); // 4�� �Լ�

	// std::bind : ���ڸ� ������ ���ο� �Լ��� ����� ����
	// ����     : std::bind(M���Լ�, M�� ����)

	auto f1 = std::bind(&foo, 1, 2, 3, 4); // 4�� �Լ� => 0 ���Լ��� �����
	f1();	// foo(1,2,3,4)


	auto f2 = std::bind(&foo, 5, _1, 4, _2); // 4�� => 2�� �Լ� �����

	f2(7, 8);	// 5, 7, 4, 8


	auto f3 = std::bind(&foo, _2, _1, 3, _3);
	f3(9, 4, 6); // 4, 9, 3, 6    �������� �� ? ä�켼��


	// �ٽ� : ��� �Լ��� bind �Ҷ��� ��ü�� ���� �����ؾ� �մϴ�.
	Sample s;
	auto f4 = std::bind(&Sample::goo, &s, 1, 2);
	f4(); // s.goo(1, 2)


	// ���� 
	// => std::bind �� ��ȯŸ���� ����ϴ� ����� ���� ��� �ٸ� Ÿ���Դϴ�.
	// => �׷���, auto �� ��ų�, std::function ���� ������ �ֽ��ϴ�.

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
	std::cout << typeid(f3).name() << std::endl;
}

