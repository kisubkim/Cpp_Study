#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	int x[5] = { 1, 2, 3, 4, 5 };
	int y[5] = { 0, 0, 0, 0, 0 };
	
	// y의 모든 요소를 x에 복사.
	for(int i=0; i<5;i++)
		x[i] = y[i];

	std::list<int> s2 = { 0,0,0,0,0 };

	// y의 모든 요소를 s2에 복사.
	auto first = s2.begin();
	auto end = s2.end();
	int i=0;
	while(first != end)
	{
		*first = y[i++];
		++first;
	}

	i = 0;
	for (auto& e:s2) {
		e = y[i++];
	}

	// 위와 같은 동작을 하는 Algorithm이 std::copy 임
	std::copy(y, y+5, s2.begin());
	// 보통 open source 에서는 아래와 같이 많이 쓰임
	std::copy(std::begin(y), std::end(y), std::begin(s2));
		
}
