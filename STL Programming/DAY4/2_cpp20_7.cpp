#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <ranges>
#include "show.h"

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	// #1. 중첩도 가능
	std::ranges::take_view tv(v, 5);
	std::ranges::reverse_view rv(tv);

	for(auto e : rv)
	{
		std::cout << e << ", ";
	}

	std::cout << std::endl;

	//^ #2. 단축 표기법 (syntax sugar) 도 제공.
	// => Linux 의 pipeline 은 흉내 낸 것.

	auto rv2 = v | std::views::filter([](int n) {return n % 2 ==0;})
				 | std::views::take(3) | std::views::reverse;
	
	for(auto e : rv2)
	{
		std::cout << e << ", ";
	}

	// 새롭게 나오고 있는 방식
	// c# 의 Linq 방식, Rust 의 iterator 방식
	//& 아래는 아직 표준에는 반영되지 않았음.
	//^ auto rv4 = v.filter(lambda).take(3).reverse();
		
}

