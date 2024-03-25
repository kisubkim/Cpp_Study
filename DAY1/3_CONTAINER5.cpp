#include <iostream>

template<typename T> struct Node
{
	T     data;
	Node* next;

	Node(const T& a, Node* n) : data(a), next(n) {}

    
};

template<typename T>
class slist_iterator
{
    Node<T>* current;
    public:
    slist_iterator( Node<T>* p = nullptr):current(p) {}

    slist_iterator& operator++ (){
        current = current->next;
        return *this;
    }

    T& operator*() { return current->data;}
    bool operator==(const slist_iterator& other) { return current == other.current; }
    bool operator!=(const slist_iterator& other) { return current != other.current; }


};

template<typename T> class slist
{
	Node<T>* head = 0;
public:
	void push_front(const T& a)
	{
		head = new Node<T>(a, head);
	}

    using iterator = slist_iterator<T>;

    iterator begin() { return iterator(head); }
    iterator end() { return iterator(0); }
};

// algorithm6에서 fine 복사

template<typename T1, typename T2>
T1 find(T1 first, T1 last, T2 c)
{
	while (first != last && *first != c)
		++first;
	return first;
}


int main()
{
	slist<int> s;

	s.push_front(10);
	s.push_front(20);
	s.push_front(30);
	s.push_front(40);
	s.push_front(50);

    // 위에서 만든 slist는 range-for 도 사용 가능.
    // range-for에 사용하고 싶으면 해당 컨테이너가 begin(), end()를 가지고 있으면 사용이 가능함.
    for( int e:s) {
        std:: cout << e << ", ";
    }

    // 위 코드는 컴파일러에 의해서 아래 코드로 변경됨.
    // 컴파일러가 수정을 함.
    auto first = s.begin();
    auto end = s.end();

    for (; first; first!=end; ++first){
        int e = *first;
        //--------------------------------
        std:: cout << e << ", ";
    }
}

/*
98년 STL의 3대 요소
 1. Container : 3일차
 2. Iterator : 1일차
 3. Algorithm : 2일차


*/ 

