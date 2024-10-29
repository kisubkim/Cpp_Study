#include <iostream>
#include <list>
#include <vector>
#include <deque>

// adapter 와 policy base design 의 결함.


template<typename T, typename C = std::deque<T>> class stack {
	C c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop() { c.pop_back(); }
	inline T& top() { return c.back(); }
};

#include<stack>		// c++ 표준의 stack이 위와 동일하게 구현이 되어 있음. 흔히 "stack adapter"라고 부름

int main()
{
	std::stack<int, std::list<int>> s3;			// c++ 표준 stack
	stack<int, std::list<int>> s1;		// list를 stack 처럼 사용하끄야!
	stack<int, std::vector<int>> s2;	// vector를 stack 처럼 사용하게쓰!
	
	stack<int> s;			// 요거는 deque 사용
	s.push(10);
	s.push(20);
	s.pop();

}
