// STL 컨테이너의 특징
#include <vector>
#include <iostream>
#include "show.h"

// 일반적 STL container 내부, using 사용 typedefine
template<typename T, typename Ax = std::allocator<T>>
class vector1
{
	Ax ax;
	public:
		using size_type = std::size_t;
		using iterator = vector_iterator;
		using value_type = T;
		using pointer = T*;
		size_type size() const { return sz; }
};

int main()
{
	std::vector<int> v = { 1,2,3 };

	// 1. 멤버 타입이 있다.
	// => ? 자리에 최선의 코드 작성 (auto 금지)
	std::vector<int>::size_type sz = v.size();
    std::vector<int>::difference_type cnt = v.end() - v.begin();
	//^ vector size의 타입은 설계자가 제일 잘 알음. -> conatiner 내부에 type 있음.

	// 2. 반환과 제거를 동시에 하지 않는다.
	// => 반환, 제거 동시는 X
	//& 그래서! 동기화!!!
	// int n = v.pop_back();	//? pop_back()은 제거 O, 반환 X
	int n = v.back();		// 반환
	v.pop_back();			// 제거


	// 3. 단위 전략을 많이 사용한다.
	std::vector<int, debug_alloc<int>> v2; // ?
}
