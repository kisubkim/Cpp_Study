#include <iostream>

// list 가 이미 있습니다
#include <list>
#include <vector>
#include <deque>

// 그런데, 스택이 필요합니다.
// 1. 새로 만들자.
// 2. list를 스택처럼 보이게 하자. <-- 요렇게 할꺼임.

//^ list의 멤버 함수이름을 stack 처럼 보이게
//^ list를 뒤에서만 입/출력이 가능하게

template<typename T>
class stack {
	std::list<T> c;
	public:
		void push(const T& a) { c.push_back(a); }
		void pop() { c.pop_back(); }
		T& top() { return c.back(); }
};
//& 위의 선언이 adaptor design pattern 으로 만든 거임.
//* adaptor pattern : 기존 class의 interface를 변경해서
//* 				다른 class 처럼 보이게 만드는 기법
//^ STL의 stack이 "adaptor pattern" 으로 설계된 것.
//& 성능 저하를 막기 위해 inline으로 만들어져 있음.

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;

}
