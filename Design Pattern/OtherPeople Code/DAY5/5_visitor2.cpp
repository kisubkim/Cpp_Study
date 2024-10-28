#include <iostream>
#include <list>
#include <vector>

// visitor 패턴 ( 약간 까다로운 내용 )
// 
// 반복자(iterator) : 복합객체의 모든 요소를 동일한 방식으로 "열거"
// 방문자(visitor)  : 복합객체의 모든 요소를 동일한 방식으로 "연산"수행

class TwiceVisitor
{
public:
	void visit(int& e) { e *= 2; }
};

template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;

	void accept(TwiceVisitor* visitor)
	{
		for (auto& e : *this)
			visitor->visit(e);
	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor tv;
	s.accept(&tv);
}

