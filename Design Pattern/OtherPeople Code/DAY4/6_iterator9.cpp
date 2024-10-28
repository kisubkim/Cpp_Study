#include <iostream>
#include <vector>
#include <ranges>

int main()
{
	std::vector v = { 1,2,3,4,5 };
	std::ranges::take_view tv(v, 2); // adapt pattern -> end, begin을 지금 기능을 바꿔주는중.
	std::ranges::reverse_view rv(tv); // adapt pattern -> end, begin을 지금 기능을 바꿔주는중.

	// prototype pattern??

	for (auto e : rv)
	{
		std::cout << e << ", ";
	}

}