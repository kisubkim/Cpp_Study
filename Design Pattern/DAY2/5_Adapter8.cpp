#include <iostream>
#include <list>
#include <vector>
#include <deque>

// adapter �� policy base design �� ����.


template<typename T, typename C = std::deque<T>> class stack {
	C c;
public:
	inline void push(const T& e) { c.push_back(e); }
	inline void pop() { c.pop_back(); }
	inline T& top() { return c.back(); }
};

#include<stack>		// c++ ǥ���� stack�� ���� �����ϰ� ������ �Ǿ� ����. ���� "stack adapter"��� �θ�

int main()
{
	std::stack<int, std::list<int>> s3;			// c++ ǥ�� stack
	stack<int, std::list<int>> s1;		// list�� stack ó�� ����ϲ���!
	stack<int, std::vector<int>> s2;	// vector�� stack ó�� ����ϰԾ�!
	
	stack<int> s;			// ��Ŵ� deque ���
	s.push(10);
	s.push(20);
	s.pop();

}
