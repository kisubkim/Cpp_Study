// 알고리즘과 멤버 함수





#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"

int main()
{
	//std::vector<int> v = { 1,2,3,1,2,3,1,2,3,1 };

    std::list<int> v = { 1,2,3,1,2,3,1,2,3,1 };
	// auto p = std::remove(v.begin(), v.end(), 3);

	// show(v);  

	// v.erase(p, v.end());

    // list도 위 코드는 에러가 없이 잘 동작하지만 성능이 좋지 않음
    // 그래서 list는 멤버함수 remove가 있음.
    v.remove(3);

	show(v);

	return 0;
}

// 핵심 : algorithm과 동일한 이름의 member function이 있다면
//* member function을 사용해라!!!!

//* 왜 member function을 제공하는가?
// 1. container iterator를 algorithm에 보낼 수 없을 때
//      std::sort(list_iterator); // error
// 2. container iterator를 algorithm에 보낼 수 있지만 보다 최적화된 구현이 있을 때
//      std::remove(list_iterator, 3)
//      list.remove(3) // 위 code보다 이게 성능이 좋다.



















//
