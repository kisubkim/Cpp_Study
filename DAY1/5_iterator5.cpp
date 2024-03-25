#include <iostream>
#include <list>

int main()
{
	std::list<int> s1 = { 1,2,3 };

	auto p1 = s1.begin();
	auto p2 = s1.end();

	// [p1, p2)

	while (p1 != p2)
	{
		++p1;
	}

	std::list<int> s3;
	if (s3.empty()) {}

	if (std::begin(s3) == std::end(s3)) {}	
}
