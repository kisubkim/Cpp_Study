#include <iostream>
#include <vector>
#include <algorithm>

bool foo(int n) { return n % 3 == 0; }
struct IsDivide{
    int value;
    IsDivide(int n) : value(n) {}

    bool operator()(int n) {return n % value == 0; }
};

int main()
{
    std::vector<int> v = {1,2,6,4,3,5,7,9, 8,10};

	int k = 3; // 사용자가 입력한 값이라고 가정.

    IsDivide f(k);      //* 1. f는 내부적으로 k값을 보관 (k값 캡쳐)
                        // 2. f는 함수처럼 사용이 가능
    bool b = f(10);     // 10 % k 의 의미.

    // 주어진 구간에서 1번째 나오는 "k의 배수" 을 찾고 싶다.
    //auto ret2 = std::find_if(v.begin(), v.end(), f); // "단항함수 + k값"을 전달하는 의미
    auto ret2 = std::find_if(v.begin(), v.end(), [](int n){return n%3==0;}); //

}

// 일반함수 : 동작은 있지만, 상태가 없음.
//            함수 수행 중 결정된 data 등을 보관할 장소가 없음.

// 함수객체 : 동작뿐 아니라, 상태가 있음. (member data가 있다는 의미)
//            즉, 멤버가 있다는 의미임. class 비슷하게 사용을 하기는 하지만 그 위치(물리적인 메모상의 위치)가 다름.

//* closure(클로져) : 현재 문맥(main함수)이 가진 지역변수를 캡쳐할 수 있는 함수.

// 함수 객체는 "closure가 될 수 있음"
// 일반 함수는 "closure가 될 수 없음"

//* 함수를 다른 곳에 인자로 보낼 때, "함수 + 지역변수"를 같이 보내기 위해 사용하는 것이 "Closure"
// C++, Java, C# rust, swift 등 대부분의 언어에 closure 개념 사용

