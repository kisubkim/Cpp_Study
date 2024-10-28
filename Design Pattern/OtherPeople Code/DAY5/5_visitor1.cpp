﻿#include <iostream>
#include <list>
#include <vector>

// visitor 패턴 ( 약간 까다로운 내용 )
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 "열거"
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 "연산"수행


int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	// #1. range-for 사용
	// => s 에서 반복자를 꺼내서
	// => 순차적으로 이동(++)하면서 각 요소에 연산을 수행하는 것
	// => "즉, 외부에서 각 요소를 꺼내서 연산"
	// => iterator 가 있는 클래스만 사용가능
	for (auto& e : s)
		e *= 2;


	// #2. 방문자(visitor) 패턴 사용

	// 1. 각 요소에 수행할 연산을 가지는 클래스 설계
	class TwiceVisitor
	{
	public:
		void visit(int& e) { e *= 2; }
	};

	// 2. 방문자 객체를 만들어서 복합객체에 넣기
	TwiceVisitor tv;
	s.accept(&tv);   // 현재는 에러. 다음예제에서 구현. 
	// <= s 가 자신이 가진 모든 요소를 tv의 visit 에 전달
	// <= 즉, 내부적으로 모든 요소에 연산 수행.

}

