#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

//& 하나의 Algorithm은 4가지의 변형이 있을 수 있음.
int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::vector<int> v2;

	// v1에서 3을 0으로 변경하는 코드입니다.
	//std::replace(v1.begin(), v1.end(), 3, 0);

	// 위 코드를 참고해서 v1에서 짝수를 0으로 변경하는 결과를 v2에 담아 보세요.
	//std::remove_copy_if(v1.begin(), v1.end(), v2.begin(), [](int n){ return n % 2 == 0;});
	std::replace_copy_if(v1.begin(), v1.end(), std::back_inserter(v2), [](int n){ return n % 2 == 0; }, 0);

	// 내가 짠거
	//std::replace_copy_if(v1.begin(), v1.end(), std::back_insert_iterator(v2), [](int n){ return n % 2 == 0; }, 0);
	show(v2);
}
