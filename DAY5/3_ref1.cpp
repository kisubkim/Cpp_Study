#include <iostream>
#include <functional>

//& reference, point (&, *) 이거는 나중에 컴파일해서 기계어 보면 동일함.

int main()
{
	int n1 = 10;
	int n2 = 20;

	// int& r1 = n1;  
	// int& r2 = n2;


	//r1 = r2;	// 이순간의 동작 방식을 생각해 보세요		//^ 값의 이동임. n1의 값이 변경됨.
	// c++ 에서 &(참조)는 const임.
	// r1은 n1의 주소를 평생 가리킴.

	//^ 1. C++ 의 참조 : 값이 이동. 참조(자체)는 상수.
	//^ 2. std::reference_wrapper : 참조 이동

	//* &, * 변수 차이점도 확인해 둘 것.
	//*

	// STL의 이동 가능한 참조. C++11S
	std::reference_wrapper<int> r1 = n1;  
	std::reference_wrapper<int> r2 = n2;

	r1 = r2;	// 여기서는 r1의 값만 변경됨.
	// 결과 예측해 보세요			// C++ 참조			reference_wrapper
	std::cout << n1 << std::endl;  //	20					10
	std::cout << n2 << std::endl;  //	20					20
	std::cout << r1 << std::endl;  //	20					20 
	std::cout << r2 << std::endl;  //	20					20 
}

