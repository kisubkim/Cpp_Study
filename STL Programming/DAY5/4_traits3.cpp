// 1번 복사// 4_traits
#include <iostream>
#include <type_traits>  // 안에 is_pointer 있음.

// STL에서 C++11부터 제공
template<typename T> void printv(const T& v)
{
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

//& error 나는 이유는 compiler 가 compile 하면서 std::is_pointer 부분을
//& 바꿀때, 최적화를 해도. if문 자체가 runtime 시에 동작하는 부분이라 해당 부분이 기계어로 만들어짐.
//* 방법은 2개. *int 처리하도록 하던가. 아니면 compile 시에 if 확인하고 정리해서 기계어로 만들던가.