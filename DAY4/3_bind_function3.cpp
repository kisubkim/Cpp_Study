#include <iostream>
#include <functional>
using namespace std::placeholders;

void f1(int a)               { printf("f1 : %d\n", a); }
void f2(int a, int b)        { printf("f2 : %d, %d\n", a, b);}
void f3(int a, int b, int c) { printf("f3 : %d, %d, %d\n", a, b, c); }
void f4(int a, int b, int c, int d) { printf("f4 : %d, %d, %d, %d\n", a, b, c, d);}

class Dialog
{
public:
	void foo(int a) { std::cout << "foo(" << a << ")" << std::endl; }
	void goo(int a, int b) { std::cout << "goo(" << a << ", " << b << ")" << std::endl; }
};

int main()
{
	// std::function : 함수 포인터를 일반화한 클래스 템플릿S
	// 사용법 : std::function<함수타입>
	
	//* 구분 잘하자~!
	//^ void(*)(int) : 함수 포인터 타입
	//^ void(int)    : 함수 타입

	std::function<void(int)> f;		// 요놈은 arg 1개인 function을 할당할 수 있음.

	f = &f1;
	f(10);		// f1(10) 과 동일

	//---------------------------------------------------
	//f = &f2;		//& 이건 error. 인자 개수가 다름.

	// std::bind() 도움을 얻으면 arg 2개를 1개로 변경이 가능
	//^ 즉 std::bind() return type 을 std::function 에 저장 가능
	f = std::bind(&f2, _1, 3);
	f(10);		// f2(10, 3); 과 동일

	f = std::bind(&f4, 8, 4, _1, 3);
	f(7);		//? f4(8, 4, 7, 3) 와 같게 위를 변경하셈

	//-----------------------------------------------------
	// member function, lambda 등 모든 호출가능한 것을 담을 수 있음.
	Dialog dlg;
	f = std::bind(&Dialog::foo, &dlg, _1);
	f(10);	// dlg.foo(10) 과 동일

	f = std::bind(&Dialog::goo, &dlg, 2, _1);
	f(10);		//? dlg.goo(2,10) 과 같게 위를 변경

}

//^ PYTHON : functools.partial 이 std::bind 임.


