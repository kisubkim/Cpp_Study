#include <iostream>
#include <list>
#include <vector>
#include <deque>

// �ذ�å 2. ����� �ƴ� ����.
template<typename T> class stack {
	std::list<T> c;
public:
	void push(const T& e) { c.push_back(e); }
	void pop() { c.pop_back(); }
	T& top() { return c.back(); }
};

int main()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.pop();

	//s.push_front(0);	// error. �Լ� ����

}

/*
	����
		=> ��� Ŭ���� �Լ��� �ܺ� ���� ���Ϸ��� "����" �ϸ� �Ǵµ�...�� private ����� ����ϳ���??

	�Ʒ� 2�� ��� �ܺο����� list�� ������ ����� �� ����.
	������ ����� ������ list �� �����Լ��� override �� �� ����.

	�� ���� ������ ������ ����.
		=> stack �� list �� �Ϻ� ��ɸ� ���������� ���
		=> �ܺ� ������ �ʿ� ����.

*/

 class stack : private list {};		// list virtual function override ����

 class stack {
	 list c;		// list virtual function override �Ұ���
 };