#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	std::sort(v.begin(), v.end(), [](int a, int b){ return a < b;});

    //------------------------------------
    // lambda 의 원리
    // => 위 코드를 컴파일러가 아래 코드처럼 변경해 줌.
    // => compiler가 lambda code를 변경시킴.
/*
    // 1. compiler가 람다식을 보고 아래와 같이 code를 만듬.
    class CompilerGeneratedName{
        public:
            inline bool operator()(int a, int b) {
                return a < b;
            }
    };

    // lambda 사용된 곳에다가 아래처럼 넣어버림. (함수객체 사용)
    std::sort(v.begin(), v.end(), CompilerGeneratedName());
    
    */
}









