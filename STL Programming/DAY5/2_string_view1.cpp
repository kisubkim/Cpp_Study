#include <iostream>
#include <string>
#include <string_view> // C++17 에서 추가

//^ string_view는 내부적으로 point 하나, int 하나 가짐.
//^ string을 가리키고, 해당 string length를 기록함.

int main()
{
	printf("aaaaaa");	//& compile 시에 compiler가 program에서 사용되는 모든 문자열을 "상수메모리"에 올림.
						// call printf

	std::string s = "to be or not to be"; 

	// #1. 아래 2줄의 차이점을 알아 두세요
	std::string      ss1 = s; 		// deep copy
	std::string_view sv1 = s;

	//std::cout << sizeof(sv1) << std::endl;

	// #2. 아래 2줄의 차이점을 알아 두세요
	std::string      ss2 = "to be or not to be";
	std::string_view sv2 = "to be or not to be";

	// c
	char aa[] = "aaaaaaaaaaaaaa";
	const char *a = "aaaaaaaaaaaaaaa";
	// 이것들 메모리 어디에 있는지 이해할 것.

}

//* 즉, string 에서 문자열을 가져가는 건 상수메모리 에서 문자열을 runtime에 자신의 heap memory에 복사한다.
//* 
