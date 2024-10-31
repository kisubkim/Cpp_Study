#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

// �Լ��� �������̽��� ����ϸ� "�����Լ�" �Դϴ�.
// �������� �̵��ϴ� ����� "�������̽�"�� ������� ����
// "����ȭ�� ���(ǥ�ع���)"

// �迭�� �����ϴ� ����� �����ϰ�(++�� �̵�, *�� ��� ����)

// "p.next()" ===> "++p" (p.operator++())
//					"*p"
template<typename T> class slist_iterator 
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}

	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}
	inline T& operator*() { return current->data; }	
};


template<typename T> struct slist 
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }

	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head); // �ӽð�ü
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

	std::cout << *it << std::endl; // 40
	++it;
	std::cout << *it << std::endl; // 30

}

// ���ڵ��

// #1. s.iterator() ��ȯ�ϴ� �ݺ��ڴ� "new" �� ����� �˴ϴ�.
//	   delete �� �ʿ����� ������� ?
//====> �ݺ��ڸ� new �� ������ ����.


// #2. �������� �̵��ϴ� next()/hasNext()�� �����Լ� �Դϴ�.
//     �����Լ��� ȣ���� ������尡 �ֽ��ϴ�.
//     next() �� �����ȿ��� ��õ ~ �������� ȣ��ɼ� �ֽ��ϴ�.

// ====> �� �ڵ�� ������ �ƴ� �ζ���!!

// #3. �迭�� collection �Դϴ�.
//     C++���� �迭�� �����Ҷ��� "������" ����մϴ�.
//     p�� �������϶� "p->next()" �Ҽ� �����ϴ�.
//		�����ʹ� ++p �� �̵�
//     "��� �÷����� ������ �������" ��� ��Ģ ����

// ===> �� �ڵ�� ++p �� �̵�. �迭�� ����
