#include <iostream>

// Step 2. 검색 구간의 일반화
// [first, last) --> 반개행 범위. 시작 포함. 끝 미만 (Harf Open Range)
char* strchr(char* first, char* last, int c)
{
	while (first != last && *first != c)
		++first;
	return first == last ? nullptr : first;
}
int main()
{
	char s[] = "abcdefgh";

	char* p = strchr(s, s+4, 'c');

    // 검색할 때, 보통 시작은 포함, 끝은 미포함. 반개행

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
