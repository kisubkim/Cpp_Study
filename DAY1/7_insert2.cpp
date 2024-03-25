// insert2.cpp
#include <iostream>
#include <algorithm>
#include <list>

// 함수 버전

int main(int argc, char** argv)
{
	int x[5] = { 10,20,30,40,50 };

	std::list<int> s1 = { 1, 2, 3, 4, 5 };
	std::list<int> s2 = { 0, 0, 0, 0, 0 };
	
	// #1. s1의 모든 요소를 s2에 "덮어쓴다"
	//std::copy(s1.begin(), s1.end(), s2.begin()); // 덮어쓴다.

	// #2. s1의 모든 요소를 s2에 "추가" - push_back 사용
	// for( auto& e:s1)
	// {
	// 	s2.push_back(e);
	// }

	// #3. Insert iterator 사용
	//std::back_insert_iterator<std::list<int>> p(s2);
	//std::copy(s1.begin(), s1.end(), p);
	
	// #4. 삽입반복자를 만드는 함수 사용
	std::copy(s1.begin(), s1.end(), std::back_inserter(s2));


	//요거 중간정도 위치로 마지막 parameter 넣었을 때 어떻게 되는지 확인 할 것. --> 이거 바로 inssert3에 했음.


	for (auto& n : s2)
		std::cout << n << std::endl; 
}
