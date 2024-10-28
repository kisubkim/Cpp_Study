#include <vector>
#include <algorithm>
#include <iostream>
#include <ranges>

//* 기존 algorithm 은 find 할 때, iterator 2개 필요
//* c++20부터 일부 iterator는 1개로 range 표현
//* 그럼 기존 STL 활용을 위해 last or end()는 어떻게 표현?
//& std::default_sentinal 을 사용

//^ c++98 range : first ~ last
//^ c++20 range : first ~ sentinel ==> 1. last 일 수도 있고
//^									   2. default_sentinel 일 수도 있음.

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	std::counted_iterator ci(v.begin(), 5);

	// ? 를 생각해 보세요
	//auto ret = std::find(ci, std::ranges::default_sentinel, 3);
	auto ret = std::ranges::find(ci, std::default_sentinel, 3);

	//while( ci.count() != 0 )
	while( ci.count() != std::default_sentinel )
	{
		std::cout << *ci << std::endl;
		++ci;
	}
}

