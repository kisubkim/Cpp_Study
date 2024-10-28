#include <iostream>
#include <list>
#include <vector>

// concrete visitor
template<typename T>
class TwiceVisitor
{
public:
	void visit(T& e) { e *= 2; }
};

template<typename T>
class ShowVisitor
{
public:
	void visit(T& e) { std::cout << e << std::endl; }
};

template<typename T>
class ResetVisitor
{
public:
	void visit(T& e) { e = 0; }
};




template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;

	// 인터페이스기반으로 다양한 방문자를 받지 말고
	// template 기반으로!
	template<typename V>
	void accept(V* visitor)
	{
		for (auto& e : *this)
			visitor->visit(e);

	}
};

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	TwiceVisitor<int> tv;
	s.accept(&tv);

	ShowVisitor<int> sv; // 요소를 출력하는 방문자 만들어 보세요
	s.accept(&sv);

	ResetVisitor<int> zv; // 요소를 0 으로 만드는 방문자
	s.accept(&zv);

	s.accept(&sv);
}




