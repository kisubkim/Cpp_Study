#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int main()
{
	//std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	auto p = s.begin();

    // std::advance : p 자체를 이동
    // std::next    : p 로부터 N 만큼 이동한 새로운 반복자 반환.
	std::advance(p, 5);      // p += 5

    auto p2 = std::next(p, 3);      // auto p2 = p + 3 의 의미임.

    auto p3 = ++p;     // 나쁘지 않지만 아래 code 권장
    auto p4 = std::next(p);     // 두번째 인자 생략 시 1로 default 설정되어 있음
	
	std::cout << *p << std::endl;
}
