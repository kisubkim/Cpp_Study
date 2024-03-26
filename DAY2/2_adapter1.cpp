#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

	auto p1 = s.begin();		// begin(), end() 는 항상 iterator 반환하는 것 잊지 말 것.
	auto p2 = s.end();		// 10 다음을 가리킴.

	// #1. reverse iterator 만들기
	std::reverse_iterator<std::list<int>::iterator> r1(p2);		// r1은 p2보다 하나 앞을 가리킴. 즉, 10을 가리킴.

	std::cout << *r1 << std::endl;
	++r1;		// reverse iterator는 ++을 하면 반대로 움직임. 즉, 10에서 부터 해서 9, 8 이런식으로 이동함.
	// reverse iterator라는 건..반대로 이동하는 것임.
	std::cout << *r1 << std::endl;

	// #2. reverse_iterator 를 만드는 3가지 방법
	// C++17 이전, 타입을 전달
	std::reverse_iterator<std::list<int>::iterator> r2(p2);

	// C++17 부터, 타입 생략 가능
	std::reverse_iterator r3(p2);

	// C++17 이전이라도 함수 버전을 사용하면 편리
	auto r4 = std::make_reverse_iterator(p2);
	
}
