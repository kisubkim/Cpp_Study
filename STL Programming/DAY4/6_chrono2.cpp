#include <iostream>
#include <chrono>

//^ duration 정의 : 특정 단위의 갯수(tick count)를 표현하는 자료구조
//^					값 하나와 단위를 관리.
//				    10초 => 1초의 10개, 10분 => 1분의 10개
//					     => 1/1000초의 10000개..

int main()
{
	// 1. duration 사용
	//	1. duration은 값 1개만 보관
	//	2. template arg 로 unit(단위) 도 전달
	std::chrono::duration<int, std::ratio<1, 100>>  d1(2); // 1/100 * 2
	std::chrono::duration<int, std::ratio<1, 1000>> d2(d1); 

	std::cout << d1.max() << std::endl;
	std::cout << d1.min() << std::endl;
	std::cout << d1.count() << std::endl;
	std::cout << d2.count() << std::endl;	// 20

	std::chrono::duration<int, std::ratio<1, 50000>> d3(d1);

	std::cout << d3.count() << std::endl; 

	// d1, d2, d3 모두 다른 type
	// duration 사용하면서 ratio 다르면 또 다른 type이 됨.

}
