#include <iostream>
#include <list>

int main()
{
	std::list<int> s1 = { 1,2,3 };

	auto p1 = s1.begin();
	auto p2 = s1.end();		// 요거 실제로는 마지막 다음 주소임. (next를 가리킴), past the last element.

	// 즉, 
	// *p1 = 10; // ok
	// *p2 = 10; // runtime error

	// [p1, p2)

	while (p1 != p2)
	{
		++p1;
	}

	// 아래 3개의 if는 모두 empty 조사
	std::list<int> s3;
	if (s3.empty()) {}

	if (std::begin(s3) == std::end(s3)) {}	
	if (se.begin() == s3.end()) {}
}
