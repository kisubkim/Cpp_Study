// iterator1.cpp
#include <iostream>
#include <list>

int main()
{
	int x[5] = { 1,2,3,4,5 };

	int* p = x;
	*p; 
	++p;

	// iterator : conatinaer' element를 가리키는 pointer 역할의 객체(instance)
	// 			진짜 포인터는 아니지만 연산자 재정의로 포인터 처럼 보이게 한 것.

	std::list<int> s = { 1,2,3,4,5 };
	std::list<int>::iterator p2 = s.begin();
	*p2; 
	++p2;
}










