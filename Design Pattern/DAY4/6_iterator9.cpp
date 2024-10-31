#include <vector>
#include <iostream>
#include <ranges>		// C++20���� 30������ view�� ������.

int main() {
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	/*std::ranges::take_view tv(v, 5);
	std::ranges::filter_view fv(tv, [](int n) { return n % 2 == 0; });
	std::ranges::reverse_view rv(fv);*/

	// �Ʒ� �ڵ�� �� �ڵ�� ������ �����մϴ�. (operator | ������ ������ ��ũ��)
	// ������ ������ ���� ó�� ����� �� �ְ� �����ϴ� ��.
	// C# ���� LINQ �� ���� �߰�, C++ ���� Pipeline ���� ����. ���� ���� ������� �����ϸ� ��.
	auto rv = v | std::views::take(5)
				| std::views::filter( [](int n) { return n % 2 == 0; } )
				| std::views::reverse;

	// C# �� �Ʒ�ó�� SQL ������� - LINQ (Languaged Integerated Query)
	//var rv = v.where(����).select(����).orderby(Ű);

	for (auto e : rv) {	// �����غ���.
		std::cout << e << ", ";
	}
	std::cout << "\n";

}