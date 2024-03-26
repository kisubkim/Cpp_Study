#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	std::vector<int> v1;				// s : 0, c : 0
	std::vector<int> v2(1000);			// s : 1000, c : 1000

	std::vector<int> v3;				// s : 0, c : 0
	v3.reserve(1000);					// s : 0, c : 1000

	v1.push_back(0);					// 메모리 재할당 O
	v2.push_back(0);					// 매모리 재할당 O, 1001번째에 0이 들어감., capacity는 compiler 마다 다를 것
	v3.push_back(0);					// 메모리 재할당 X

	std::cout << v1.size() << ", " << v1.capacity() << std::endl;
	std::cout << v2.size() << ", " << v2.capacity() << std::endl;
	std::cout << v3.size() << ", " << v3.capacity() << std::endl;

	return 0;
}

