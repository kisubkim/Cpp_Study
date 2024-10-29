#include <iostream>
#include <list>
#include <vector>
#include <deque>

/*
	stack�� ���Ӱ� ������� ���� �۾��� �ʿ�.
	list�� �Լ� �̸��� �����ؼ� stack ó�� ���̰� �غ���.
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

	// �� �ڵ�� "����� ����� stack adapter"
	// ���� : �������� ������. (list �� �ƴ� stack ���)
	// ���� : �Ʒ�ó�� �Ǽ� �� �� ����.
	s.push_front(0);		// List�� ���� ������������ ��밡��. ������ ����� �� ���� �ؾ���.

	// ��������� ����� ����� stack adapter : ���� ������.
	// => java stack �� �̷��� �Ǿ� ����.
	// => �׷��� java ������ stack ������� ����� ����.
}