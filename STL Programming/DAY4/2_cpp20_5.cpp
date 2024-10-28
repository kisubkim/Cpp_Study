#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <ranges>
#include "show.h"

int main()
{
	std::list<int> s1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	std::list<int> s2 = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

	// s1 의 모든 내용을 s2로 복사해 보세요
	// 98 style
	//std::copy(s1.begin(), sq.end(), se.begin());

	// 20 style
	// => range 가 요구되는 인자를 "container name" 으로 전달 가능.
	std::ranges::copy(s1, s2.begin());
	// ranges 에 있는 function들 모두 가능
	
	show(s2);
}

