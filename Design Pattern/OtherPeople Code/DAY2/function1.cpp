// function1.cpp
#include <iostream>
#include <functional>	// std::bind() 가 이헤더에 있습니다.
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
	foo(1, 2, 3, 4); // 4항 함수

	// std::bind : 인자를 고정한 새로운 함수를 만드는 도구
	// 사용법     : std::bind(M항함수, M개 인자)

	auto f1 = std::bind(&foo, 1, 2, 3, 4); // 4항 함수 => 0 항함수로 만들기
	f1();	// foo(1,2,3,4)


	auto f2 = std::bind(&foo, 5, _1, 4, _2); // 4항 => 2항 함수 만들기

	f2(7, 8);	// 5, 7, 4, 8


	auto f3 = std::bind(&foo, _2, _1, 3, _3);
	f3(9, 4, 6); // 4, 9, 3, 6    나오도록 위 ? 채우세요


	// 핵심 : 멤버 함수는 bind 할때는 객체도 같이 전달해야 합니다.
	Sample s;
	auto f4 = std::bind(&Sample::goo, &s, 1, 2);
	f4(); // s.goo(1, 2)


	// 참고 
	// => std::bind 의 반환타입은 사용하는 방법에 따라 모두 다른 타입입니다.
	// => 그래서, auto 에 담거나, std::function 에만 담을수 있습니다.

	std::cout << typeid(f1).name() << std::endl;
	std::cout << typeid(f2).name() << std::endl;
	std::cout << typeid(f3).name() << std::endl;
}

