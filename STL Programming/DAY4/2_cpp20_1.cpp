#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

//^ c++98부터 17까지는 utility 성 항목들만 추가되었음.
//^ 그런데 c++20부터는 새로운 개념이 많이 추가됨.

//* c++20 핵심
//* c++98 : 구간을 표현하려면 "2개 operator"
//* c++20 : operator 1개로 구간 표현 가능. ex> std::counted_iterator

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	// c++20 에서 새로 추가된 iterator
	// para1 의 iterator에서 para2 만큼 range를 가지는 iterator 제공.
	std::counted_iterator ci(v.begin(), 5);		//* ci는 v 시작부터 5개를 가지는 range
	// std::countedPiterator<std::vector<int>::iterator>> ci(v.begin(), 5);
	// 원래 위와 같은 구문이 생략된 형태.

	while( ci.count() != 0 )
	{
		std::cout << *ci << std::endl;
		++ci;
	}

}
