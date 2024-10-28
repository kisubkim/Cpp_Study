#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v = { 1,2,3,4,5 };

	// 아래 for 의 원리를 생각해 봅시다.
	for (auto e : v)
	{
		std::cout << e << ", ";
	}

	// 위 코드는 컴파일러가 아래 처럼 변경합니다.(C#, java, python 모두 동일한 원리)
	auto first = v.begin();
	auto last = v.end();

	for (; first != last; ++first)
	{
		auto e = *first;
		//----------------------------
		std::cout << e << ", ";
	}
}