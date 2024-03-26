#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"
#include "chronometry.h"

void memoryallocCheck1(int n){
	std::vector<int, debug_alloc<int>> v1(n);
}

int main()
{
	//chronometry();
	std::vector<int, debug_alloc<int>> v1;				// s : 0, c : 0
	chronometry(memoryallocCheck1(100));

	v1.reserve(100);

	// 아래 code는 메모리 할당이 몇번이 일어날까?
	for (int i=0; i < 30; i++) {
		v1.push_back(0);
	}
	return 0;
}

