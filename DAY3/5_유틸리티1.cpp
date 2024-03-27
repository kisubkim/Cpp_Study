#include <iostream>
#include <tuple>
#include "show.h"

int main()
{
	// pair : 서로다른 타입 2개를 보관하는 구조체
	std::pair<int, double> p1(1, 2.4);

	std::cout << p1.first << std::endl;
	std::cout << p1.second << std::endl;

	std::pair<int, std::pair<double, int>> p2 (1, {3.4, 2});
	std::cout << p2.second.first << std::endl;

	//^ C++11 부터 pair의 일반화 version인 tuple 제공
	std::tuple<int, double, int> t1(1, 10.4, 3);
	std::cout << std::get<2>(t1) << std::endl;		// get에 변수를 넣을 수는 없음. 무조건 상수

	//^ pair, tuple을 만드는 함수도 있음
	//auto p3 = std::make_pair(1, 2,2);		// 어..이거 왜 error 나지..확인 필요.
	auto p4 = std::make_tuple(1, 1.1, 5.5, 3);
}


