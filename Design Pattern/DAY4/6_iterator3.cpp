#include <iostream>
#include <vector>
#include <list>

/*
	아래는 실행이 안됨.
	Java의 반복자를 사용하는 법을 설명해줌.
*/

int main()
{
	slist<int>  s = { 1,2,3 };
	vector<int> v = { 1,2,3 };

	// java style iterator 코드

	// 1. 컨테이너(컬렉션)에서 반복자를 꺼내려면 "iterfator()" 함수 사용
	//		=> 모든 컬렉션에는 iterator() 함수가 있다. ->  컬렉션이 지켜야 하는 Interface가 있다 
	auto it1 = s.iterator();
	auto it2 = s.iterator();

	// 2. it1, it2는 다른 컬렉션의 반복자 객체
	//		=> 그런데, 사용법은 동일 --> 모든 iterator class가 지켜야 하는 규칙이 있음.
	while (it1.hasNext())	// next 부를 수 있는지 확인
	{
		std::cout << it1.next() << std::endl;
		// 1. it1 이 가리키던 값 반환
		// 2. it1 다음으로 이동
	}

	while (it2.hasNext())
	{
		std::cout << it2.next() << std::endl;
	}
}
