#include <iostream>
#include <list>
#include <vector>
#include <deque>

/*
	stack을 새롭게 만들려면 많은 작업이 필요.
	list의 함수 이름만 변경해서 stack 처럼 보이게 해보자.
*/

template<typename T> class stack : public std::list<T> {
public:
	void push(const T& e) { std::list<T>::push_back(e); }
	void pop() { std::list<T>::pop_back(); }
	T& top() { std::list<T>::back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();

	// 위 코드는 "상속을 사용한 stack adapter"
	// 장점 : 가독성이 좋아짐. (list 가 아닌 stack 사용)
	// 단점 : 아래처럼 실수 할 수 있음.
	s.push_front(0);		// List로 부터 물려받음으로 사용가능. 하지만 사용할 수 없게 해야함.

	// 결론적으로 상속을 사용한 stack adapter : 나쁜 디자인.
	// => java stack 이 이렇게 되어 있음.
	// => 그래서 java 에서는 stack 사용하지 말라고 권장.
}