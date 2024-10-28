#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10 };

	// container에서 꺼낼 수 있는 Iterator는 4가지 종류가 있음.
	// 1. 정방향 반복자
	std::list<int>::iterator p1 = s.begin(); 	// 제일 앞을 가리킴. ++ 하면 정방향

	// 2, 역방향 반복자
	std::list<int>::reverse_iterator p1 = s.rbegin();	// 제일 마지막 element를 가리킴. ++하면 역방향

	// 3. 상수 반복자
	std::list<int>::const_iterator p1 = s.cbegin();		// 이녀석은 쓰기 금지, 읽기는 가능

	// 4. 상수 역방향 반복자
	std::list<int>::const_reverse_iterator p1 = s.crbegin();
}
