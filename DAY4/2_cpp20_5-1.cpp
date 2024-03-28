#include <string>
#include <algorithm>
#include <functional>
#include <iostream>

int main() {
	std::string s1 = "ABC";
	std::string s2 = "XY";

	auto ret1 = std::max(s1, s2);		// "XY"	s1, s2 를 < 연산으로 비교


	// s1, s2 중 문자열의 길이가 큰 것은?
	auto ret2 = std::ranges::max(s1, s2);

	auto ret3 = std::max(s1.size(), s2.size());		// 이건 return type 이 int
	//* s1, s1 의 멤버 중 4st 인자(projection)로 보낸 member를 호출한 결과를
	//* 3st 인자로 보낸 함수(객체)로 비교하고
	//* s1, s2 --> projection 을 통과한 결과를 ==> 비교함수로 전달.
	auto ret4 = std::ranges::max(s1, s2, std::less{}, &std::string::size);

	

	return 0;
}