// 1번 복사// 4_traits
#include <iostream>
#include <type_traits>  // 안에 is_pointer 있음.

// STL에서 C++11부터 제공
template<typename T> void printv(const T& v)
{
	// if constexpr : 컴파일 시간 if 문
	//				  조건식은 반드시 컴파일 할 때 계산할 수 있어야함.
	//				  조건식이 false 인 경우
	//				  "template => C++함수 생성" 에서 제외됨.
	if ( std::is_pointer<T>::value )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;

	printv(n);  // 이 code 때문에 error
	printv(&n);
}

