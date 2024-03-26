#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

//* 알고리즘은 컨테이너를 알지 못한다.


// std::remove : 조건을 만족하는 element를 찾으면 실제 메모리 제거가 아닌
//				뒤의 element를 앞으로 이동시킴
//				또한 container 자체의 크기도 줄이지 않음
//				반환 값으로 유효하지 않은 구간의 시작을 나타내는 반복자 반환.

//* algoritm은 "container를 알 수 없기 때문에" memory를 제거할 수(줄일 수)는 없음.
//* 크기, 메모리를 제거하려면 "Member Function"으로 해야함.
// 그래서 container 크기와 관련된 함수들은 모두 member function임.
int main()
{
	std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

	auto p = std::remove(v.begin(), v.end(), 3);

	show(v);  

	// container 요소 제거는 일반함수(algorithm)이 아닌 멤버함수로 해야함.
	v.erase(p, v.end());

	show(v);


	return 0;
}



















//
