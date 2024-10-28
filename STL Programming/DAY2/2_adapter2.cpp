#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

	// 앞에서 부터 검색
	auto ret1 = std::find(s.begin(), s.end(), 3);	

	// 뒤에서 부터 검색
	auto ret2 = std::find(s.rbegin(), s.rend(), 3);
	// 이 reverse iterator 때문에 모든 algorithm은 역방향으로도 사용을 할 수 있음.
}
