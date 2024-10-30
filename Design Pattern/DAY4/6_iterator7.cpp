#include <vector>
#include <iostream>

int main() {
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// python	: for e in v
	// c#		: for var e in v

	for (auto e : v) {
		std::cout << e << ", ";
	}
	std::cout << "\n";

	// 위 for 문의 원리
	// 위 코드를 컴파일러는 아래처럼 변경.
	auto first = v.begin();
	auto last = v.end();

	for (; first != last; ++first) {
		auto e = *first;
		//--------------
		std::cout << e << ",";		// 사용자 code
	}
}