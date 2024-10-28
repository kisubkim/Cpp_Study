#include <iostream>

//^ T가 포인터 인지를 조사하는 기술
template<typename T> struct is_pointer{
	// 왜 enum?
	// c++11 이전에는 bool value = false; 와 같이 멤버 초기화가 불가능했었음.
	//& bool 로 선언하면 컴파일 시간 상수가 아님
	enum { value = false; }
};

//^ 요즘 사용하는 방식 (c++11)
template<typename T> struct is_pointer_new{
	static constexpr bool value = false;		// 실제 c++ standard는 이렇게 구현되어 있음.
};

// template 부분 특수화 (template partial specialization)
template<typename T> struct is_pointer<T*>{
	enum { value = true; }
};

template<typename T> void foo(const T& b)
{
	if (is_pointer<T>::value)
		std::cout << "포인터" << std::endl;
	else
		std::cout << "포인터 아님" << std::endl;
	
}

int main()
{
	int n = 10;

	printv(n);
	printv(&n);
}

