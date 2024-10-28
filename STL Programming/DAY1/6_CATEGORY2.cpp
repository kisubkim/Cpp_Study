#include <iostream>
#include <vector>
#include <list>
#include <forward_list>
#include <algorithm>

int main()
{
	std::forward_list<int> s1 = { 1,2,3 };
	std::list<int> s2 = { 1,2,3 };
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// find 는 1, 2번째 인자가 iterator
	// => 최소 요구 조건을 위의 5가지에서 선택해 보세요. --> 요건 1번만 돌면 되니까 입력이 최소 조건.
	// 만약 2번 돌아야 한다면 전진형 Iterator가 최소 조건이 됨.
	auto p = std::find(v.begin(), v.end(), 5);

	std::reverse(v.begin(), v.end());	// 1, 2 번째 인자의 최소 요구 조건은?
										// => 양방향 (bidirectional iterator
										
	//std::reverse(s1.begin(), s1.end());		// error 이유는 위에
	std::reverse(s2.begin(), s2.end());		// ok

	std::sort(v.begin(), v.end());		// quick sort(하이브리드 버젼) algorithm
										// => 반 짜를려면 - 이거 지원해야함. 그래서 random access iterator 가 최소 조건.

	//std:;sort(s2.begin(), s2.end());		// error.
	s2.sort();		// ok. 이거는 quick sort가 아닌 다른 구현을 사용함.
					// 그래서 멤버 함수 sort() 제공함.

	// vector의 member function이 가장 적은 이유는. algorithm이 따로 다 제공되는 걸 사용하면 되기 때문임.
	// 즉, 특정 구조체의 member function이 많다는건 좋다고 하기 힘듬.

	v.sort()		// 이거 있을까? ==> 없음.
					// sort 하고 싶으면 std::sort() 사용
					// vector의 iterator는 random access iterator라서 모든 일반 함수(algorithm) 사용이 가능.
}

// 교재 53page
//* 교재에서 표에 0 표시 되어 있는 건, 무조건 되어야 하는 조건을 말함.
// 만약에 표시가 되어 있지 않다고 지원하지 않는다는 것은 아님. (그냥 될 수도 있고, 안될 수도 있음.)

// 입력 (input iterator) : =*p, ++
// 출력 (output iterator) : *p=, ++

// 위 2개는 multiple pass 보장 x
// 아래 4개는 multiple pass 보장함.

// 전진형 (forward iterator): =*p, ++
// 양방향 (bidirectional iterator): =*p, ++, --
// 랜덤 액세스 (random access iterator): =*p, ++, --, +, -, []
// 연속메모리 (contigous iterator):

//* 1. Iterator 분류 외워라.
//* 2. 각 container iterator가 어떤 category인지 외워라 
//*  => list : bidirectional iterator
//*     vector : random access iterator
//* 3. 각 Algorithm (일반 함수)의 최소 요구사항을 알고 있어야함.
//*  => std::find : input
//*  => std::sort : random access
//* 4. std::sort90 에 std::list iterator 사용 불가한 이유 알아야함.
//*
