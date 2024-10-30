#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

/*
	규칙 
		1. 모든 반복자는 아래 인터페이스를 구현해야 한다.
		2. 모든 컬렉션은 아래 인터페이스를 구현해야 한다.
*/

// 1st rule 구현
template<typename T>
struct IIterator {
	virtual T& next() = 0;
	virtual bool hasNext() = 0;
	virtual ~IIterator() {}
};		// 1st rule 정리

// 2nd rule 구현
template<typename T>
struct ICollection {
	virtual IIterator<T>* iterator() = 0;
	virtual ~ICollection() {}
};
//--------------------------------------------------------------

/*
	Java style로 만든 single List Iterator
	Iterator 핵심
		1st Element를 가리키다가 약속된 방법으로 이동.
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

 //slist_iterator it(300번지)

template<typename T> struct slist : public ICollection<T>
{
	Node<T>* head = 0;
public:
	void push_front(const T& a) { head = new Node<T>(a, head); }
	IIterator<T>* iterator() override {
		// slist_iterator 객체를 list 첫번째 요소 주소로 초기화해서 반환.
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
	위 방식이 대부분의 OOL (C#, Java, Python, Swift, etc) 가 사용하는 방식

	C++ 진영에서 위 방식에 대해서 생각하는 문제점
		1. s.iterator() 반환하는 바복자는 "new"로 만듬
		   --> 그럼 당연히 delete 가 필요한데...어디서 지움??

		2. 다음으로 이동하는 next() / hasNex()가 가상함수이다.
		   --> 가상함수 호출의 오버헤드가 있음.
		   --> next() 는 루프안에서 수천~수만번 호출될 수 있음.

		3. 배열도 collection 임.
		   --> C++에서 배열을 열거할 때는 "포인터" 사용함. (포인터는 ++p 로 이동)
		   --> p가 포인터 일때 "p->next()" 할 수 없음. ("모든 컬렉션을 동일한 방법으로" 라는 규칙 위배)

*/