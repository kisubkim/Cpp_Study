#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"

// 단항함수 (unary function) : 인자가 한 개인 함수
// 이항함수 (binary function) : 인자가 두 개인 함수

//* for_each 의 3번째 인자는 단항함수.

void foo(int n){
    std::cout << n << ", ";
}

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    // STL은 많은 algorithm이 인자로 함수를 받음.
    // for_each 알고리즘
    std::for_each(v.begin(), v.end(), foo);     // p1 부터, p2까지 1개쌕, p3에다가 순서대로 던짐


	return 0;
}



















//
