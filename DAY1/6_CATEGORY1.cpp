#include <forward_list>
#include <list>

int main()
{
	std::forward_list<int> s1 = { 1,2,3 };

	std::list<int> s2 = { 1,2,3 };

	auto p1 = s1.begin();
	auto p2 = s2.begin();
	
	++p1;
	--p1;
	++p2;
	--p2;

}
