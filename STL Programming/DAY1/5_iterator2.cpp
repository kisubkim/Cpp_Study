#include <iostream>
#include <list>
#include <filesystem>


// iterator의 종류
// 1. Container에서 꺼내는 것
// 2. 독립적으로 만들어서 사용하는 Iterator 도 있음.
// 3. raw pointer 도 iterator의 일종

// Iterator : *로 element 접근 가능. ++로 이동 가능한 모든 것
int main()
{
	// container에서 꺼내서 사용.
	std::filesystem::directory_iterator p("C:\\windows");

	std::cout << *p << std::endl;
	++p;
	std::cout << *p << std::endl;
}










