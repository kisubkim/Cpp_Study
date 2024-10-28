#include <vector>
#include <list>
#include <iostream>
#include <algorithm>
#include "show.h"



int main()
{
	std::vector<int> v1(10, 0);
	v1[0] = 10;
	
	// 컨테이너를 보관하는 컨테이너
	//std::vector<std::vector<int>> v2(10);		// v2 자체 size 10, v2[0] size 자체가 없음.
	//std::vector<std::vector<int>> v2(10, 10);	// error
	//std::vector<std::vector<int>> v2(10, {5});	// ok. v2[0].size는 1
	//std::vector<std::vector<int>> v2(10, std::vector<int>(10));		// ok. v2[0] size 10
	v2[0][0] = 10;
	std::cout << v2[0].size() << std::endl;

	std::vector<std::list<int>> v3(10);
	
}
