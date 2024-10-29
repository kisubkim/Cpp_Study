#include <iostream>
#include <vector>

int main()
{
	std::vector<int> v;								// 이 code는 결국 아래 code 임.
	// std::vector<int, std::allocator<int>> v;		// 이렇게 동작하는 것과 같음.


	v.resize(4);

}
