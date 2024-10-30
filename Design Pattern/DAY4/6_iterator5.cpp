#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& d, Node* n) : data(d), next(n) {}
};

//--------------------------------------------------------------

// 함수를 interface로 약속하면 "가상함수" 임.
// 다음으로 이동하는 방법을 "interface"로 약속하지 말고, "문서화"로 약속.(표준문선)

// 배열을 열거하는 방법과 동일하게 (++로 이동, *로 요소 접근)
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
	위 방식이 대부분의 OOL (C#, Java, Python, Swift, etc) 가 사용하는 방식

	C++ 진영에서 위 방식에 대해서 생각하는 문제점
		1. s.iterator() 반환하는 바복자는 "new"로 만듬
		   --> 그럼 당연히 delete 가 필요한데...어디서 지움??
		   ==> 위 코드는 new 로 만들지 않음.

		2. 다음으로 이동하는 next() / hasNex()가 가상함수이다.
		   --> 가상함수 호출의 오버헤드가 있음.
		   --> next() 는 루프안에서 수천~수만번 호출될 수 있음.
		   => 위 코드는 가상이 아닌 인라인.

		3. 배열도 collection 임.
		   --> C++에서 배열을 열거할 때는 "포인터" 사용함. (포인터는 ++p 로 이동)
		   --> p가 포인터 일때 "p->next()" 할 수 없음. ("모든 컬렉션을 동일한 방법으로" 라는 규칙 위배)
		   => 위 코드는 ++p로 이동. 배열과 동일

*/