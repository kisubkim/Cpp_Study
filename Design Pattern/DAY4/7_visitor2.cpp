#include <iostream>
#include <list>
#include <vector>

/*
	방문자(visitor)  : 요소 한개에 대한 연산을 정의하는 객체
*/

template<typename T>
struct IVisitor {
	virtual void visit(T& e) = 0;
};

template<typename T>
class TwiceVisitor : public IVisitor<T> {
public :
	void visit(T& e) override { e *= 2; }
};

template<typename T>
class ShowVisitor : public IVisitor<T> {
	void visit(T& e) override { e *= 2; }
};

template<typename T>
struct IContainter {
	virtual void accept(IVisitor<T>* visitor) = 0;
};

template<typename T>
class MyList : public std::list<T>, public IContainter<T> {
public:
	// **** 생성자 상속 사용해야함. ****
	using std::list<T>::list;

	void accept(IVisitor<T>* visitor) override {
		for (auto& e : *this) {
			visitor->visit(e);
		}
	}
};

int main()
{
	//std::list<int> s(10, 0);		// ok. std::list 에는 인자 2개 생성자 있음.

	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };		// error MyList<int> 에는 인자 2개 생성자가 없음.

	// visitor 를 사용하는 코드
	//		=> 의미 : "요소 한개에 대한 연산의 정의" 만 container 에 전달
	//				 container 가 내부적으로 모든 요소를 방문자에게 전달
	TwiceVisitor<int> tv;
	s.accept(&tv);
}





