#include <iostream>
#include <list>
#include <iterator>

// 삽입반복자종류

int main(int argc, char** argv)
{
	int x[5]    = { 1, 2, 3, 4, 5 };
	std::list<int> s = { 0, 0, 0, 0, 0 };

	// 후방 삽입
	//std::copy(x, x+5, std::back_inserter(s));		// 0,0,0,0,0,1,2,3,4,

	//* 전방 삽입 (뒤집어서 들어감)
	//std::copy(x, x+5, std::front_inserter(s));		// 5,4,3,2,1,0,0,0,0,0

	// 임의 삽입
	//std::copy(x, x+5, std::inserter(s, std::next(s.begin(), 3)));		// 0,0,0,1,2,3,4,5,0,0

	//* front insert 사용하면 뒤집어서 들어가지만, 임의 삽입으로 넣으면 순서대로 들어감.
	std::copy(x, x+5, std::inserter(s, s.begin()));		// 1,2,3,4,5,0,0,0,0,0
	for (auto& n : s)
		std::cout << n << ", ";
}
