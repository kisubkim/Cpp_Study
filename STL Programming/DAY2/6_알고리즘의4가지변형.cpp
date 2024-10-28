#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

//& 하나의 Algorithm은 4가지의 변형이 있을 수 있음.
int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2 = { 0,0,0,0,0,0,0,0,0,0 };

	//^ 1. 기본형 (in place ver.)
	//auto p1 = std::remove(v1.begin(), v1.end(), 3);

	//^ 2. Predicator version (조건자)
	//auto p2 = std::remove_if(v1.begin(), v1.end(), [](int n){ return n%3==0; });

	//^ 3. Copy version
	auto p3 = std::remove_copy(v1.begin(), v1.end(), v2.begin(), 3);
	// 여기서 p3은 v2의 iterator 가 된다. <-- v2에서 이동하면서 값을 넣어야 하니까!
	// v2에다가 복사하고 remove 할려면 for문 2번 돌아야 하기 때문에 remove_copy로 한방에 해결
	//& xxx_copy() 는 copy 처리로 인해서 성능이 확실하게 차이가 나는 것에만 제공된다.

	//^ 4. Copy Predicator version
	auto p3 = std::remove_copy_if(v1.begin(), v1.end(), v2.begin(), [](int n){ return n % 3 == 0;});

	show(v1);
	show(v2);
}
