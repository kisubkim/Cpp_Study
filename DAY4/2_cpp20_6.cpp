#include <vector>
#include <list>
#include <algorithm>
#include <iostream>
#include <ranges>
#include "show.h"

//^ view 는 resource를 가지고 보는게 아니라 빌려서 본다.
//^ 즉, vector 가 있으면, 그걸 보는 시점만 바뀌어서 보고, 따로 메모리를 할당하지는 않음.

template<typename R>
class take_view{
	R& rg;
	std::size_t cnt;
	public:
		take_view(R& r, std::size_t c) : rg(r), cnt(c) {}

		auto begin() { return rg.begin(); }
		auto end() { return std::next(rg.begin(), cnt); }
};

template<typename R>
class reverse_view{
	R& rg;
	public:
		reverse_view(R& r) : rg(r) {}

		auto begin() { return rg.rbegin(); }
		auto end() { return rg.rend(); }
};

int main()
{
	std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};

	take_view tv(v, 5);

	//for(auto e : v)
	//for(auto e : tv)
	for(auto e : reverse_view(v))
	{
		std::cout << e << ", ";
	}	
}

