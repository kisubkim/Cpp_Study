#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
	//std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

	// 반복자 p를 5칸 전진하고 싶다.
	p = p + 5;		// vector와 같은 random access iterator 를 가지는 container 만 가능.
	
	++p; ++p; ++p; ++p; ++p;		// 요거는 가능. 모든 iterator에 가능. 하지만 너무 느림

	// 따라서 아래처럼 하면 좋음!!
	std::advance(p, 5);		//* iterator 종류에 따라서 속도가 빠른 이동을 진행함.
	
	std::cout << *p << std::endl;
}
