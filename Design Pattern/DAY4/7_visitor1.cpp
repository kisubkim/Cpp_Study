#include <iostream>
#include <list>
#include <vector>

/*
	Visitor pattern - 이해하기 어려운 패턴. (그래서 c++에서는 잘 안씀)

	반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 열거
	방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 연산수행
*/

template<typename T>
struct IVisitor {

};

template<typename T>
class TwiceVisitor : public IVisitor<T> {

};

template<typename T>
class ShowVisitor : public IVisitor<T> {

};

template<typename T>
struct IContainter {
	virtual void accept(IVisitor*) = 0;
};

template<typename T>
class slist : public std::list<T>, public 

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	// s의 모든 요소를 2배로 하고 싶다.

	// 방법 1. 외부에서 모든 요소를 열거해서 2배
	//		=> 원리 : s 에서 iterator 를 꺼내서 ++ 로 이동하면서 element 접근.
	//		=> 핵심 : s 의 모든 element 를 외부에서 열거 한 것.
	//		=>		Iterator 가 없으면 불가능.
	for (auto& e : s) {
		e = e * 2;
	}

	// 방법 2. Visitor pattern 사용
	//		=> 외부에 열거하는 코드는 없음. --> 컨테이너 내부에서 열거 (다음예제)
	TwiceVisitor<int> tv;		// 요소를 2배로 하는 일을 하는 visitor
	s.accept(&tv);				// s 에 visitor를 방문 시킴.

	ShowVisitor<int> sv;		// 요소를 출력하는 일을 하는 방문자
	s.accept(&sv);

	/*
		규칙
			1. accept는 모든 종류의 visitor 를 받아야 한다.
				-> 모든 방문자의 공통의 interface 필요.
				-> accept( IVisitor* )

			2. List 뿐 아니라 vector, set, map 에는 accept 가 있어야 한다.
				-> 모든 컨테이너는 accept 가 있어야 한다.
				-> container 의 common interface 가 필요.
	*/

}





