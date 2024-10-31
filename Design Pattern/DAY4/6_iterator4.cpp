#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

/*
	��Ģ 
		1. ��� �ݺ��ڴ� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
		2. ��� �÷����� �Ʒ� �������̽��� �����ؾ� �Ѵ�.
*/

// 1st rule ����
template<typename T>
struct IIterator {
	virtual T& next() = 0;
	virtual bool hasNext() = 0;
	virtual ~IIterator() {}
};		// 1st rule ����

// 2nd rule ����
template<typename T>
struct ICollection {
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//--------------------------------------------------------------

/*
	Java style�� ���� single List Iterator
	Iterator �ٽ�
		1st Element�� ����Ű�ٰ� ��ӵ� ������� �̵�.
*/

template<typename T>
class slist_iterator : public IIterator<T> {
	Node<T>* current;
public:
	slist_iterator(Node<T>* p = 0) : current(p) {}
	T& next() override {
		T temp = current->data;
		current = current->next;
		return temp;
	}
	
	bool hasNext() override {
		return current != 0;
	}
};

 //slist_iterator it(300����)

template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	IIterator<T>* iterator() override {
		// slist_iterator ��ü�� list ù��° ��� �ּҷ� �ʱ�ȭ�ؼ� ��ȯ.
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

	while (it->hasNext()) {
		std::cout << it->next() << std::endl;
	}

	delete it;
}

/*
	�� ����� ��κ��� OOL (C#, Java, Python, Swift, etc) �� ����ϴ� ���

	C++ �������� �� ��Ŀ� ���ؼ� �����ϴ� ������
		1. s.iterator() ��ȯ�ϴ� �ٺ��ڴ� "new"�� ����
		   --> �׷� �翬�� delete �� �ʿ��ѵ�...��� ����??

		2. �������� �̵��ϴ� next() / hasNex()�� �����Լ��̴�.
		   --> �����Լ� ȣ���� ������尡 ����.
		   --> next() �� �����ȿ��� ��õ~������ ȣ��� �� ����.

		3. �迭�� collection ��.
		   --> C++���� �迭�� ������ ���� "������" �����. (�����ʹ� ++p �� �̵�)
		   --> p�� ������ �϶� "p->next()" �� �� ����. ("��� �÷����� ������ �������" ��� ��Ģ ����)

*/