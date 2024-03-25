#include <iostream>

// Step 1. C 표준 함수
char* strchr(char* s, int c)
{
	while (*s != 0 && *s != c)
		++s;
	return *s == 0 ? 0 : s;
}
int main()
{
	char s[] = "abcdefgh";

	// strchr : 표준에 있는 문자열 찾는 함수.
	char* p = strchr(s, 'c');

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
