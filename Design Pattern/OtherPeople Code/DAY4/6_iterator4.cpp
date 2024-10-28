#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;
	Node(const T& d, Node* n) : data(d), next(n) {}
};

// ��� �ݺ��ڰ� ���Ѿ� �ϴ� ��Ģ
template<typename T>
struct IIterator
{
	virtual bool hasNext() = 0;
	virtual T& next() = 0;

	virtual ~IIterator() {}
};

// ��� �����̳�(�÷���)�� ���Ѿ� �ϴ� ��Ģ
template<typename T>
struct ICollection
{
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};

//----------------------------------
// �̱۸���Ʈ�� �ݺ��� �ڵ�
// => 1��° ��Ҹ� ����Ű�� �����͸� ������ �ִٰ�
// => ��ӵ� �Լ����� �̵��Ҽ� ������ �˴ϴ�.
template<typename T>
class slist_iterator : public IIterator<T>
{
	Node<T>* current;
public:
	slist_iterator(Node<T>* p) : current(p) {}

	// ���� ��ӵ� �Լ� ����
	T& next() override
	{
		T& ret = current->data;

		current = current->next;

		return ret;
	}

	bool hasNext() override { return current != nullptr; }
};



// �����̳�(collection) ������ iterator �� ������ �־�� �մϴ�.
template<typename T> class slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }


	IIterator<T>* iterator() override
	{
		return new slist_iterator<T>(head);
	}
};

int main()
{
	slist<int> s;
	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);

	auto it = s.iterator();

	while (it->hasNext())
	{
		std::cout << it->next() << std::endl;
	}

	delete it;
}


// C++ ��� �������� �� �ڵ��� ����

// #1. s.iterator() �� ��ȯ�� �ݺ��ڴ� "new" �� �����ߴ�
// => delete �ؾ� ���� ������ ?


// #2. �������� �̵��ϴ� �Լ� "next" �� �����Լ� �Դϴ�.
// => ������� �ֽ��ϴ�.
// => �����ȿ��� ȣ��ɼ� �ִ� �Լ� �̹Ƿ� ������ �߿�


// #3. Raw Array �� ��ȯ�Ҷ��� "raw pointer" ����ؼ� ++�� �̵��մϴ�.
// => �ᱹ �̵� ����� �ٸ��� �˴ϴ�.
// => ��� "�÷����� ������ ���" �� ���� �˴ϴ�.
