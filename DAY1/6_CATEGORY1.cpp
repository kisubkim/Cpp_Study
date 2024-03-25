#include <forward_list>
#include <list>

// 가장 중요
int main()
{
	std::forward_list<int> s1 = { 1,2,3 };		// single linked list

	std::list<int> s2 = { 1,2,3 };		// double linked list

	auto p1 = s1.begin();
	auto p2 = s2.begin();
	
	// 아래 중에서 error는?
	++p1;
	--p1;		// 요거! -- operator 재정의 가능하기는 한데, 자료구조상 이유로 구현은 되어 있지 않음.
	++p2;
	--p2;

	// C++에서는 반복자를 6가지로 분류함.

}
