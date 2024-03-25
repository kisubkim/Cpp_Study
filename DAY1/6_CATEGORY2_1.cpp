#include <forward_list>
#include <list>

// 가장 중요
int main()
{
	std::forward_list<int> s1 = { 1,2,3 };		// single linked list

	std::list<int> s2 = { 1,2,3 };		// double linked list

	auto p1 = s2.begin();
    auto p2 = s2.cbegin();  // const iterator. 쓰기 안됨.
    *p1 = 10;         // mutable iterator
    //*p2 = 20;          // error, immutable iterator
	
}
