#include <iostream>
#include <functional>

void foo(int& a) { a = 200; }

// 2nd arg를 다른 함수로 전달
//  ==> call by value 로 동작.
template<typename F, typename T> 
void forward(F f, T arg)
{
	f(arg);
}
int main()
{
	int n = 10;

	//foo(n);	// 직접 전달, n은 200으로 변경됩니다.

	//forward(foo, n); // 복사본 생성됨.
	//forward(foo, &n); // 주소 전달.
						// T arg = &n에서 T = int* 임으로
						// foo(int*)가 되서 error


	// std::reference_wrapper<int> r = n;
	// forward(foo, r);

	forward(foo, std::ref(n));		// std::ref 가 reference_wrapper 를 만들어 주는 함수.
									//& ==> "object generator" 기술, c++11

	std::cout << n << std::endl; 
}

// 에초에 값으로만 인자로 받는 STL도 있음.
// 이럴 때, reference_wrapper 로 넘기면 참조를 넘길 수 있음.
