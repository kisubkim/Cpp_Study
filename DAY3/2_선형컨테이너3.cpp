#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

// 예전에 만들어 놓은 함수 (c 로 만들었다고 치자)
// => 배열의 시작, 갯수를 받는 c 시절 만든 함수라고 가정.
void foo(int* arr, int sz) {}

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
	foo(x, 10);

	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };

	// foo 에 v를 보내 보세요.
	foo(v, v.size());		// error, vector instance
	foo(&v, v.size());		// error, vector의 addr
	foo(&v[0], v.size());		// ok. c++98시절 사용
	foo(v.data(), v.size());	//^ ok. c++11 이후

	foo(v.begin(), v.size());	// error. data를 가리키는 임의 object 임.
}


