// function1.cpp

#include <iostream>
#include <functional>

// 4�� �Լ� : Arf�� 4���� �Լ�
void foo(int a, int b, int c, int d) {
	std::printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

using namespace std::placeholders;		// _1, _2, _3...

int main() {
	foo(1, 2, 3, 4);

	/*
		std::bind() ���� : std::bind(M�� �Լ��ּ�, M�� ����);
	*/

	auto f1 = std::bind(&foo, 1, 2, 3, 4);	// foo�� ���� 4���� 1, 2, 3, 4�� ������ ���ο� �Լ� f1
											// 4�� => 0�� �Լ��� ����
	f1();

	auto f2 = std::bind(&foo, 3, 8, _1, _2);
	f2(4, 7);		// foo(3, 8, 4, 7)

	auto f3 = std::bind(&foo, _2, 3, _3, _1);
	f3(8, 2, 6);		// foo(2, 3, 6, 8) �ǵ��� ? ä���?

}

/*
	python : functools.partial(�Լ�, ����, ...)
*/