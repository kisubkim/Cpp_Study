#include <iostream>
#include <type_traits>

template<typename T>
using remove_pointer_t = typename std::remove_pointer<T>::type;		// c++14

//^ type traits 종류
//^ 1. 타입 질의 : std::is_pointer<T>::value    ----> bool
//^ 2. 변형 타입얻기 : std::remove_pointer<T>::type   ---> T가 int* 면 int, 포인터를 제거한 타입.

template<typename T> void foo(const T& b)
{
	typename std::remove_pointer<T>::type n;

	std::cout << typeid(n).name() << std::endl;

	// 조사
	bool b1 = std::is_pointer<T>::value;		// c++11
	bool b2 = std::is_pointer_v<T>;				// c++17

	// 변형된 type
	//typename std::remove_pointer<T>::type n;		// 1st ver, c++11
	// 2nd ver는 위에 using 포함임.
	remove_pointer_t<T> nn;		// 요거는 개념확인 용.
	std::remove_pointer_t<T> nnn;		// 이건 STL. C++17
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

