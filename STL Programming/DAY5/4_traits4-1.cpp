#include <iostream>
#include <type_traits>
#include <vector>


template<typename T>
void foo(T& c){
	? n = c.front();

	// auto 는 반드시 우변 필요
	// c의 요소와 같은 타입의 변수를 보관하는 container가 필요하면?
	std::vector<typename T::value_type> v2; // ok

	// value_type이 없는 container 면?
	// decltype() 을 사용하면 타입 조사 가능
	decltype(c.front()) n2;		// error. compile 할 때, c.front() 의 type을 compiler 한테 찾아달라는 code임.
								// 이거 결과는 value가 아닌 value& 임. ==> //& error
	typename std::remove_reference<decltype(c.front())>::type n2;	// ok

	// 이게 위처럼 vector 만들려면
	std::vector<typename std::remove_reference<decltype(c.front())>::type> v3;	// ok
};




int main() {
	std::vector<int> v{1,2,3};
	foo(v);
}