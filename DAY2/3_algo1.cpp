#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

// 알고리즘 기본
// algorithm 이 STL에서는 일반함수를 의미하.
// 일반적인 의미 : 문제를 해결하는 방법
// STL 에서는 : std::find 같은 일반함수 템플릿

// <algorithm>, <numeric> 쪽에 있음.
// 핵심 -> member function이 아닌 generic function 이며, 전부 template 으로 구현되어 있음.
int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };
	
	auto p = std::find( v.begin(), v.end(), 3);

	return 0;
}



















//
