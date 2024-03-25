#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}
};

// slist 안에 있는 요소를 가리키는 포인터 역할의 객체만들기.

template<typename T>
class slist_iterator
{
    Node<T>* current;
    public:
    slist_iterator( Node<T>* p = nullptr):current(p) {}

    // 연산자 재정의 덕분에 ++, * 연산가능해짐.
    slist_iterator& operator++ (){
        current = current->next;
        return *this;
    }

    T& operator*() { return current->data;}

    // find 할려면 ==, != 이것도 되어야함.

    bool operator==(const slist_iterator& other) { return current == other.current; }
    bool operator!=(const slist_iterator& other) { return current != other.current; }

    // c++의 모든 고급 기법은 연산자 재정의 에서 나옴.

};

template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

    // find로 검색. 시작, 마지막 가리키는 반복자 필요
    slist_iterator<int> begin() { return slist_iterator<int>(head); }
    slist_iterator<int> end() { return slist_iterator<int>(0); }
};

int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

    slist_iterator<int> p1 = s.begin();
    slist_iterator<int> p2 = s.end();
    // p1은 객체.
    // 내부에 operator 재정의 되어 있음

    std::cout << *p1 << std::endl;
    ++p1;
    std::cout << *p1 << std::endl; 
}
