#include <vector>
#include <iostream>
#include <ranges>		// C++20부터 30여개의 view가 제공됨.

int main() {
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	/*std::ranges::take_view tv(v, 5);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 0; });
	std::ranges::reverse_view rv(fv);*/

	// 아래 코드는 위 코드와 완전히 동일합니다. (operator | 연산자 재정의 테크닉)
	// 리눅스 파이프 라인 처럼 사용할 수 있게 지원하는 것.
	// C# 에서 LINQ 로 먼저 했고, C++ 에서 Pipeline 으로 만듬. 왼쪽 부터 순서대로 진행하면 됨.
	auto rv = v | std::views::take(5)
				| std::views::filter( [](int n) { return n % 2 == 0; } )
				| std::views::reverse;

	// C# 은 아래처럼 SQL 방식으로 - LINQ (Languaged Integerated Query)
	//var rv = v.where(조건).select(조건).orderby(키);

	for (auto e : rv) {	// 생각해보자.
		std::cout << e << ", ";
	}
	std::cout << "\n";

}