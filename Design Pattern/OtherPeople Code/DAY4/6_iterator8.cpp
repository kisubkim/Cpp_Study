#include <iostream>
#include <vector>

template<typename T>
class take_view
{
	T& rgn;
	int cnt;
public:
	take_view(T& r, int c) : rgn(r),cnt(c){}

	auto begin() { return rgn.begin(); }
	auto end() { return rgn.begin() + cnt; }
};

int main()
{
	std::vector v = { 1,2,3,4,5 };
	take_view tv(v, 2); // adapt pattern -> end, begin을 지금 기능을 바꿔주는중.

	// prototype pattern??

	for (auto e : tv)
	{
		std::cout << e << ", ";
	}
}