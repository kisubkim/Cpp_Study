#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

	auto p1 = s.begin();
	auto p2 = s.end();

	// #1. reverse iterator 만들기
	std::reverse_iterator< > r1(p2);

	std::cout << *r1 << std::endl;
	++r1;
	std::cout << *r1 << std::endl;
	
}
