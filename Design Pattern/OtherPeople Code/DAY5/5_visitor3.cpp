#include <iostream>
#include <list>
#include <vector>

// 모든 방문자의 규칙(인터페이스)
template<typename T> struct IVisitor
{
	virtual void visit(T& e) = 0;
	virtual ~IVisitor() {}
};

// concrete visitor
template<typename T>
class TwiceVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { std::cout << e << std::endl;}
}; template<typename T>

class ResetVisitor : public IVisitor<T>
{
public:
	void visit(T& e) { e = 0; }
};

// 모든 복합객체(컨테이너)의 인터페이스
template<typename T> struct IAcceptor
{
	virtual void accept(IVisitor<T>*) = 0;
	virtual ~IAcceptor() {}
};

template<typename T> class MyList : public std::list<T>,
public IAcceptor<T>
{
public:
	using std::list<T>::list;

	void accept(IVisitor<T>* visitor)
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




