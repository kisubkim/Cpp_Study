#include <iostream>
#include <list>   
#include <vector>

// 반복자 무효화
int main()
{
	std::vector<int> v = { 1,2,3,4,5 };
	
	auto p = v.begin();

	std::cout << *p << std::endl;
}



