#include <iostream>
#include <list>
#include <iterator>

int main(int argc, char** argv)
{
	std::list<int> s = { 1, 2, 3, 4, 5};

	// container 끝에 element 추가하는 방법
	// 1. push_back() 사용
	s.push_back(10);
	std::cout << s << std::endl;

	// 2. insert iterator(삽입 반복자) 사용. C++98 부터
	std::back_insert_iterator<std::list<int>> p1(s);		// s의 긑에 추가하는 iterator, c++98 ver
	auto p3 = std::back_inserter(s);		// Object Generator 로 만든 삽입 반복자를 만드는 함수 템플릿 사용.
	// auto 는 C++11 부터 지원. 즉, OG는 C++11부터 만들어졌다고 봐야함.

	std::back_insert_iterator p2(s);		// s의 긑에 추가하는 iterator, c++17 ver (type 생략 가능)

	*p1 = 20;		// s.push_back(20);
	*p2 = 22;
}
