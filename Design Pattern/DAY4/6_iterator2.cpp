#include <iostream>

// 아래 코드는 "싱글 링크드 리스트" 입니다.

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

template<typename T> struct slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
};

/*
	그림으로 어떻게 한 줄이 실행될 때마다 변경되는지는 알아 둘 것.
*/

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
}
