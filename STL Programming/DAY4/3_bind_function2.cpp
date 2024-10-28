#include <iostream>
#include <algorithm>
#include <functional>
using namespace std::placeholders;

// 4항 함수
void foo( int a, int b, int c, int d)
{
    printf("%d, %d, %d, %d\n", a, b, c, d);
}

int main()
{
    foo(1,2,3,4);   // 4항 함수

    //^ std::bind : 기존 함수(객체)의 특정 인자를 고정한 새로운 함수 만드는 도구
    //^             M 항 함수 => N항 함수로 만들기 (단, M >= N)
    //^ 사용법 : std::bind(&M항함수, M개 인자)
    //* _1, _2, _3 : placeholders 라고 하고, std::placeholders 안에 있음.
    //* _1 => std::placeholders::_1
    auto f1 = std::bind(&foo, 1, 2, _1, _2);        //& foo() 에서 1st, 2nd 인자를 1, 2 로 fix 하고, 3rd, 4th 를 입력받는 형태로 변환.

    f1(10,20);      // foo (1,2,10,20) 과 동일

    auto f2 = std::bind(&foo, _2, _3, 6, _1);       //? foo 의 arg 가 4개니까 일단 4개 다 적기는 해야함.
    f2(9, 4, 8);        // foo(4, 8, 6, 9) 가 나오게 해보셈!

    //^ std::bind() 의 return type 은 "함수객체" 임.
    //^ bind() 인자에 따라 모두 다른 type 이다.
    std::cout << typeid(f1).name() << std::endl;
    std::cout << typeid(f2).name() << std::endl;

    // bind() return type 이 다르기 때문에
    //& "container" 에 보관이 불가능 ==> 해결책은 std::function

}

