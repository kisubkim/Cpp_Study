#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};


//----------------------------------
// 1. ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ�� "����" �� ����մϴ�.
// 2. �������� �̵��ϰ� ��� ������ "raw pointer" �� �����ϰ� ����ϵ���!!
// => operator++, operator* ������ ������ 

template<typename T>
class slist_iterator
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p) : current(p) {}


	inline slist_iterator& operator++()
	{
		current = current->next;
		return *this;
	}

	inline T& operator*() { return current->data; }


	inline bool operator!=(const slist_iterator& s) { return current != s.current; }

	inline bool operator==(const slist_iterator& s) { return current == s.current; }
};


template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	slist_iterator<T> begin()
	{
		return slist_iterator<T>(head); // �����Ҵ��� �ƴ� �ӽð�ü(��)�� ��ȯ
	}

	slist_iterator<T> end()
	{
		return slist_iterator<T>(0);
	}

};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto first = s.begin();
	auto last = s.end();

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}


	//	auto it = s.begin();
	//	std::cout << *it << std::endl; // 40
	//	++it;
	//	std::cout << *it << std::endl;	// 30
}




// STL ����� �� �ڵ��

// #1. s.iterator() �� ��ȯ�� �ݺ��ڴ� "new" �� �����ߴ�
// => delete �ؾ� ���� ������ ?

// ===> s.begin() ���� "new" ������� �ʰ�, ������ ��ȯ!



// #2. �������� �̵��ϴ� �Լ� "next" �� �����Լ� �Դϴ�.
// => ������� �ֽ��ϴ�.
// => �����ȿ��� ȣ��ɼ� �ִ� �Լ� �̹Ƿ� ������ �߿�

// ===> operator++() ������ �ƴ� �ζ��� �Լ�!! C�� ���� ����. 


// #3. Raw Array �� ��ȯ�Ҷ��� "raw pointer" ����ؼ� ++�� �̵��մϴ�.
// => �ᱹ �̵� ����� �ٸ��� �˴ϴ�.
// => ��� "�÷����� ������ ���" �� ���� �˴ϴ�.

// ===> operator++() ,operator*() ����ϹǷ� "�����Ϳ� ������ ����"