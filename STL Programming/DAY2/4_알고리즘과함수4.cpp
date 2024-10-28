#include <iostream>
#include <vector>
#include <algorithm>
#include "show.h"


void foo(int n){ std::cout << n << ", "; }

int main()
{
    std::vector<int> v = {1,2,3,4,5,6,7,8,9,10};
    
    std::for_each(v.begin(), v.end(), foo); 

    // c++11부터 제공되는 lambda 표현식
    // 람타표현식 : 함수 이름(주소)가 필요한 위치에 함수 구현 자체를 적을 수 있는 문법
    //              이름 없는 함수를 만드는 문법
    // [] : lambda introducer
    //      람다표현식이 시작됨을 알리는 기호
    std::for_each(v.begin(), v.end(), [](int n){ std::cout << n << ", "; });


	return 0;
}




