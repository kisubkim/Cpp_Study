﻿#include <iostream>
#include <vector>
#include <list>

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// java style iterator 코드
	// => 컴파일 되지 않습니다. 설명을 위한 코드.

	// 핵심 #1. 모든 컨테이너에는 반복자를 꺼내는 iterator() 함수가 있다
	// => 컨테이너의 인터페이스 필요
	auto it1 = s.iterator();
	auto it2 = v.iterator();


	// 핵심 #2. 모든 iterator 는 사용법이 같아야 한다.
	// => iterator 의 인터페이스가 필요

	while (it1.hasNext())
	{
		std::cout << it1.next() << std::endl;
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}