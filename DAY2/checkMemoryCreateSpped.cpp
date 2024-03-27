#include "chronometry.h"
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

//& vector는 무조건 reserve() 사용해서 할당할 것. 속도차가 너무남.

void memoryallocCheck1(){
	std::vector<int, debug_alloc<int>> v1;
	v1.reserve(100000000);
}

void memoryallocCheck2() {
	std::vector<int, debug_alloc<int>> v(100000000);
}

void memoryallocCheck3(){
	std::vector<int, debug_alloc<int>> v1;
	v1.resize(100000000);
}


int main()
{
	
	chronometry(memoryallocCheck1);
	chronometry(memoryallocCheck2);
	chronometry(memoryallocCheck3);
	//chronometry([](){std})

	return 0;
}

