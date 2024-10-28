#include <iostream>
#include <list>   
#include <vector>
#include <ranges>

// g++ 5_iterator3.cpp -std=c++20

int main()
{
	//std::list<int> s = { 1,2,3,4,5 };
	//std::vector<int> s = { 1,2,3,4,5 };
	int s[] = { 1,2,3,4,5 };

	// 반복자를 꺼내는 법
	// 1. c++98 style
	// => 단점 : 아래처럼 사용하면 컨테이너 변경시 아래 코드도 변경해야함.
	//std::list<int>::iterator p = s.begin(); // 선언에서 container 교체시에 여기도 수정이 필요함.

	// 2. auto를 권장함.
	// => 수정을 많이 할 필요가 없어짐.
	//auto p = s.begin();

	// 3. member가 아닌 일반함수 std::begin() 이 좀 더 유연성이 있음.
	//auto p = std::begin(s);	// s가 배열이라도 ok.

	// 4. C++20 부터 새로운 begin 등장함.
	auto p = std::ranges::begin(s);		// 가장 안전한 code

	auto p1 = std::begin(std::list{1,2,3});		// ok. 아...
	//auto p2 = std::range::begin(std::list{1,2,3});		// error. 임시 객체가 안으로 들어왔을 때 error로 되면서 좀 더 안전해짐.
}



