// function1.cpp

#include <iostream>
#include <functional>

void foo(int a, int b, int c, int d) {
	std::printf("foo : %d, %d, %d, %d\n", a, b, c, d);
}

void foo1(int a) {}
void foo2(int a, int b) {}

using namespace std::placeholders;

int main() {
	// C 언어의 함수 포인터는 유연성이 부족.
	//void(*f1)(int) = &foo1;		// ok
	//f1 = &foo2;		// error, foo2는 인자가 2개. f1은 인자 1개짜리 포인터.

	// C++ std::function 은 "함수포인터" 를 대체해서 사용.
	// 사용법 : std::function<함수모양>
	std::function<void(int)> f1;		// 요거는 void를 리턴하고 함수 인자가 int 하나다~.
	f1 = &foo1;
	f1(10);		// foo1(10)

	//f1 = &foo2;		// error. foo2는 인자 2개라서 똑같이 error. 그.런.데.
					// std::function은 std::bind 결과를 담을 수도 있다!. 하지만 항 개수는 동일해야함.
	f1 = std::bind(&foo2, 3, _1);
	f1(10);		// foo2(3, 10);

	f1 = std::bind(&foo, 3, 5, _1, 0);
	f1(9);		// foo(3, 5, 9, 0);

	/*
		결론
			std::function<void(int)> 는 인자가 int 1개 이상인 함수라도 std::bind()를 사용하면 모두 주소를 담을 수 있음.
			std::function<void()> 는 모든 종류의 함수를 담는다.
	*/
}
