#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// vector 가 resize가 작게 변경되면 기존 메모리는 계속사용함.
// capacity 개념 : vector size는 7이지만 capacity는 10임.
int main()
{
	std::vector<int> v(10, 0);

	v.resize(7); // 어떻게 구현했을까요 ?

	std::cout << v.size() << ",  " << v.capacity() << std::endl;

	v.push_back(0);	// 끝에 0 추가
					// size < capacity 이므로 메모리 재할당 없음.
					// not expensive!!
	std::cout << v.size() << ",  " << v.capacity() << std::endl;

	v.shrink_to_fit();		//& 필요없는 메모리 제거. 딱 맞게 메모리 재할당해서 copy 후 사용. 기존 buf 제거

	std::cout << v.size() << ",  " << v.capacity() << std::endl;

	v.push_back(0);		// size == capacity 상태이기 때문에 메모리 재할당 필요
						//& expensive 연산!
						//^ compiler마다 자동으로 늘이는 양이 틀림. mscv는 1.5배, g++은 2배 <--기존 capacity의 배수임

	std::cout << v.size() << ",  " << v.capacity() << std::endl;
}




