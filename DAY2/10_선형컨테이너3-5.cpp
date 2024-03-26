#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"
#include "chronometry.h"

int main()
{
	std::vector<int> v1(10);				// s : 0, c : 0

	v1.resize(4);

	//& 핵심 : vector의 복사 생성자에 대해서!!
	// 복사 생성할 때 target의 size에 맞도록 capacity를 조정함.
	std::vector<int> v2 = v1;

	std::cout << v2.size() << ", " << v2.capacity() << std::endl;

	// c++98 시절에는 shrink_to_fit()이 없었음. C++11 부터 shrink_to_fit()이 제공됨.
	// 그 이전에는 아래처럼 처리 진행.
	
	std::vector<int> v3(10);
	v3.resize(4);

	std::cout << v3.capacity() << std::endl;

	// shrink_to_fit() 없이 제거
	std::vector<int>(v3).swap(v3);

	std::cout << v3.capacity() << std::endl;
	return 0;
}

