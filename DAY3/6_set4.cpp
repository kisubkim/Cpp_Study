#include "show.h"
#include <set>

struct Compare
{
	bool operator()(int a, int b) const
	{
		return (a / 10) < (b / 10);
	}
};

int main()
{
	std::set<int, Compare> s;
	
	// #1. 다음중 실패는 ?
	s.insert(15);
	s.insert(25);
	s.insert(45);
	s.insert(35);
	s.insert(22); 		// fail. 10자리 2는 위에 25 있음.
	show(s);

	// #2. 아래 2개의 검색 결과는 어떻게 나올까요 ?
	// #2-1. equivalency 
	auto ret1 = s.find(12); 	// binary search
								// => root 와 비교해서 left, right decision
								//& == 연산이 아닌 set에 전달한 함수 객체를 사용해서 찾음.
								//& 따라서 15를 찾게됨. (동일이 아니라 동등한 것을 찾음)
	
	if (ret1 == s.end())
		std::cout << "fail" << std::endl;
	else 
		std::cout << *ret1 << std::endl;


	// #2-2. 아래 코드가 equality
	//* algorithm std::find()는 == 연산
	auto ret2 = std::find(s.begin(), s.end(), 12); 
	if (ret2 == s.end())
		std::cout << "fail" << std::endl;
	else 
		std::cout << *ret2 << std::endl;
	

}
