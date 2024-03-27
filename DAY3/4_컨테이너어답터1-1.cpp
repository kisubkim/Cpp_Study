#include <iostream>
#include <list>
#include <vector>
#include <deque>

//^ policy base design

template<typename T, typename Container = std::deque<T>>
class stack {
	protected:		//& 핵심!!!. 즉, queue 같은 내부 구조를 알고 싶으면 상속받아서 접근하면 됨.
	Container c;
	public:
		void push(const T& a) { c.push_back(a); }
		void pop() { c.pop_back(); }
		T& top() { return c.back(); }
};

#include <stack>	// STL 에서 위와 동일한 형태로 만들어짐.
					// "stack adaptor" 라고 부름.

int main()
{
	stack<int, std::list<int>> s;		// list를 stack으로 사용하겠다. 근데 불편하니까 최적화 -> default 추가
										//^ 요게 STL stack 만들어진 방식
	s.push(10);
	s.push(20);

	std::cout << s.top() << std::endl;

}
