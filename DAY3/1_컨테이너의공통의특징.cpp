// STL 컨테이너의 특징
#include <vector>
#include <iostream>
#include "show.h"

int main()
{
	std::vector<int> v = { 1,2,3 };

	// 1. 멤버 타입이 있다.
	? sz = s.size();
    ? cnt = v.end() - v.begin();

	// 2. 반환과 제거를 동시에 하지 않는다.
	int n = v.pop_back();	// ?


	// 3. 단위 전략을 많이 사용한다.
	std::vector<int, debug_alloc<int>> v2; // ?
}
