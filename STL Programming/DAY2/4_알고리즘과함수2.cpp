#include <iostream>
#include <list>
#include <algorithm>
#include "show.h"

// stl에서 인자로 list or vector등을 2개 넣을 때, 처음에는 구간이 처음과 끝이 있는데
// 두번째는 시작만 있는 경우, 두 컨테이너가 같은 크기를 가진다고 가정한다.
// 두번째 container는 절대 첫번째보다 크기가 작으면 x

int foo(int a, int b){
    return a + b;
}

int main()
{
    std::list<int> s1 = { 1,2,3,4,5};
    std::list<int> s2 = { 6,7,8,9,10 };
    std::list<int> s3;

    // transform 알고리즘 -> 요넘은 이항연산임.
    // 아래에서 처음에 시작부터 엔드까지, 1개씩 넣을때, s2의 element로 1개씩 같이 foo로 넣고, 그 결과를 s3에다가
    // 추가하는 것임.
    std::transform( s1.begin(), s1.end(), // 1. 이 구간의 내용을
                    s2.begin(),           // 2. 이 구간의 내용과 함께
//                    s3.begin(),           // 3. 함수 결과를 여기에 넣어라
                    std::back_inserter(s3),
                    foo);                 // 4. 이 함수에 보내서

    show(s3);

	return 0;
}



















//
