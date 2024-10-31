#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

//--------------------------------------------------------------

// �Լ��� interface�� ����ϸ� "�����Լ�" ��.
// �������� �̵��ϴ� ����� "interface"�� ������� ����, "����ȭ"�� ���.(ǥ�ع���)

// �迭�� �����ϴ� ����� �����ϰ� (++�� �̵�, *�� ��� ����)
// "p->next()" ===> "++p" (p.operator++())
//					"*p"
template<typename T>
class slist_iterator {
	Node<T>* current;
public:
	inline slist_iterator(Node<T>* p = 0) : current(p) {}
	inline slist_iterator<T>& operator++() {
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }
};

template<typename T> struct slist {
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	slist_iterator<T> begin() {
		return slist_iterator<T>(head);
	}
};


int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto it = s.begin();
	std::cout << *it << std::endl;
	++it;
	std::cout << *it << std::endl;
}

/*
	�� ����� ��κ��� OOL (C#, Java, Python, Swift, etc) �� ����ϴ� ���

	C++ �������� �� ��Ŀ� ���ؼ� �����ϴ� ������
		1. s.iterator() ��ȯ�ϴ� �ٺ��ڴ� "new"�� ����
		   --> �׷� �翬�� delete �� �ʿ��ѵ�...��� ����??
		   ==> �� �ڵ�� new �� ������ ����.

		2. �������� �̵��ϴ� next() / hasNex()�� �����Լ��̴�.
		   --> �����Լ� ȣ���� ������尡 ����.
		   --> next() �� �����ȿ��� ��õ~������ ȣ��� �� ����.
		   => �� �ڵ�� ������ �ƴ� �ζ���.

		3. �迭�� collection ��.
		   --> C++���� �迭�� ������ ���� "������" �����. (�����ʹ� ++p �� �̵�)
		   --> p�� ������ �϶� "p->next()" �� �� ����. ("��� �÷����� ������ �������" ��� ��Ģ ����)
		   => �� �ڵ�� ++p�� �̵�. �迭�� ����

*/