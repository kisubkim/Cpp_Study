#include <vector>
#include <iostream>
#include <ranges>		// C++20부터 30여개의 view가 제공됨.

int main() {
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	std::ranges::take_view tv(v, 5);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 0; });
	std::ranges::reverse_view rv(fv);

	for (auto e : rv) {	// 생각해보자.
		std::cout << e << ", ";
	}
	std::cout << "\n";

}