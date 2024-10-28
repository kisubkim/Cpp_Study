// 3_함수객체1
#include <iostream>

struct Plus		// 이거는 구조체 structure
{
	int operator()(int a, int b)
	{
		return a + b;
	}
};
int main()
{
	Plus p; 	// p는 instance

	int n = p(1, 2); 	// 객체인 p를 함수처럼 사용
						//* "함수 객체" 라고 부름.
	int n1 = p.operator()(1,2);		// 위 코드를 compiler가 이렇게 해석함. 이 코드로 사용해도 무방함.
}

// function object => () 연산자를 재정의해서 함수처럼 사용이 가능한 객체

// why?? 일반함수를 만들지 않고, 함수 객체를 사용하는가?
// 1. 상태를 가지는 함수 - closure
// 2. 특정 문맥에서 함수객체가 함수 보다 삐름.
// 3. 그 외에도 장점이 너무 많음.

// C++20에서 추가된 대부분의 표준 함수는 "함수가 아닌 함수객체"
