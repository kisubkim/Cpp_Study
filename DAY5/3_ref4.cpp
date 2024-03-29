#include <iostream>
#include <functional>

void foo(int& a) { a = 200; }

int main()
{
	std::function<void()> f;

	int n = 10;

	//f = &foo;		// error. foo는 한개를 요구.
	//f = std::bind(&foo, n);		// 이 순간 foo의 인자를
								// 1. n으로 고정?
								// 2. n의 값 10으로 고정? <-- 이렇게 사용됨.

	f = std::bind(&foo, std::ref(n));		// 이렇게 하면 reference로 보관
											// 정확한 원리는 pointer로 보관하다가 참조로 변환 가능한 것.

	
	f();		// foo(n) ? foo(10)
	// std::bind()는 값의 메카니즘임.
	// f() 전에 {} 쳐서 내용 머리속으로 이해할 것. => 이미 사라진 n을 참조로 물고 있으면 난리남.

	std::cout << n << std::endl; 
}
