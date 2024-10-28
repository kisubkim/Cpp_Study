#include <iostream>
#include <list>
#include <vector>

template<typename T> class MyList : public std::list<T>
{
public:
	using std::list<T>::list;

	template<typename V>
	void accept(V visitor)
	{
		for (auto& e : *this)
			visitor(e); // visitor 는 함수 이거나
		// visitor.operator()(e)
		// 즉, visitor 는 () 연산자가 있어야 한다.
	}
};

void twice(int& e) { e *= 2; }


int main()
{
	MyList<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	s.accept(twice); // 일반 함수 전달

	// 또는 아래처럼 람다 표현식
	// => 람다 표현식은 함수 처럼 () 호출 가능. 
	s.accept([](int& e) { e *= 2; });
	void (*printfp)(int& e)([](int& e) { std::cout << e << ", "; });
	s.accept(printfp);
	s.accept([](int& e) { e *= 3; });
	s.accept(printfp);
}


