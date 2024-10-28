#include <iostream>
#include "show.h"

#include <set> // Red Black Tree로 구현

//^ 표준 문서 : set을 구현할 때 Tree를 사용하라고 강제하지는 않음.
//^ 		    그런데 standard 에서, 그리고 대다수의 compiler는 Read black Tree 로 되어 있음.
//              왜??? 싼가??, 구현이 쉽나??

int main()
{
	std::set<int> s;

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);
	s.insert(17);
	s.insert(25);

	auto first = s.begin();		// 가장 왼쪽의 Node
	auto last  = s.end();		// 오른쪽 마지막 다음 Node

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
	
}







