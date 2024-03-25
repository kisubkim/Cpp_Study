// insert2.cpp
#include <iostream>
#include <algorithm>
#include <list>

// 함수 버전

int main(int argc, char** argv)
{
	int x[5] = { 10,20,30,40,50 };

	std::list<int> s = { 1, 2, 3, 4, 5 };
	
	std::copy(x, x + 5, s.begin()); // 덮어쓴다.


	for (auto& n : s)
		std::cout << n << std::endl; 
}
