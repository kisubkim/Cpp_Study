// 1_STL_PREVIEW1
#include <iostream>
#include <list>
#include <vector>

int main()
{
	std::list<int> s;

	int x[5] = {1,2,3,4,5};

	// 배열 : 크기 변경을 할 수 없음.
	// 바꾸고 싶으면 vector 사용하면 됨.
	vector<int> x[5] = {1,2,3,4,5};
	x.resize(10);
}
