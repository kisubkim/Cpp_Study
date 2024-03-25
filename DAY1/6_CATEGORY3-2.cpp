#include <iostream>
#include <vector>
#include <list>
#include <iterator>

int x[5]{1,2,3,4,5};
int* forst() { return x; }

int main()
{
	std::vector<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	
    // 2번째 부터 검색한다고 하면, 아래 2개 code 모두 동작은 함. 하지만 2번째 code로 하는게 더 좋음.
    auto p1 = std::find(++s.begin(), s.end(), 3);
    auto p2 = std::find(std::next(s.begin()), s.end(), 3);       // best!

    auto p3 = ++first();        // error. 함수의 return 값으로 받는 주소를 바로 ++로 하는 것은 안됨. 
    auto p4 = std::next(first());       // ok.0
