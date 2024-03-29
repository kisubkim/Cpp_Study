#include <iostream>
#include <string>
#include "show.h"
using namespace  std::literals;

void foo(const char* s) { std::cout << "const char*\n";} // 1
void foo(const std::string& s) { std::cout << "string";} // 2

int main()
{
	foo("hello"); //? 1번 호출됨. hello 의 정확한 type은 const char[6]
				  //  ==> const char[] 은 const char* 로 암시적 변환 가능.
	foo("hello"s);		// 2번 호출. literal 사용하기 위한 namespace 선언 필요

	auto s1 = "hello";		// s1 : const char*
	auto s2 = "hello"s;		// s2 : string
}