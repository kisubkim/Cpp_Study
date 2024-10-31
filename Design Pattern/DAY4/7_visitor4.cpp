#include <iostream>
#include <list>
#include <vector>

/*
	visitor3.cpp 는 전통적인 디자인 기법으로 만든 방문자.
	
	visitor(방문자) 를 만들 때
		1. IVisitor 에서 상속되어야 하고
		2. visit() 함수가 가상함수 이므로 오버헤드가 있음.

	C++ style 로 다시 만들어 보자.

*/


template<typename T>
class MyList : public std::list<T> {
public:
	using std::list<T>::list;

	// 여러 방문자를 받기 위해 
	//		1. interface를 사용하지 말고 template 으로
	//		2. "v->visit(e)" 가 아니라 v(e) 죽, v 픞 () 로 호출가능해야 함.

	// 이 부분은 member function 을 template member function 으로 사용을 한 예제임.
	template<typename V>
	void accept(V v) {
		for (auto& e : *this) {
			v(e);
		}
	}
};

void foo(int& e) { e *= 2; }

int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	s.accept([](int& e) { std::cout << e << " "; });
	std::cout << std::endl;

	s.accept(foo);
	s.accept([](int& e) { std::cout << e << " "; });

	/*
		Java의 collection 들이 위와 같은 기능이 있음.
		Lamda 표현식으로 전달.
	*/
}





