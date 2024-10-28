// 알고리즘과 멤버 함수





#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include "show.h"


// member function은 generic function 보다 일반적으로 속도가 빠름.
// 해당 구조체에 최적화된 함수를 제공함. (즉, algorithm에 같은 이름이 있어도 member에 있으면 member에 있는 걸 써야함)
int main()
{
    std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 };
    std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

    // container를 뒤집을 때 사용하는 함수 이름은 "reverse"
    // v와 s를 뒤집어라.
    //v.reverse();      // error
    std::reverse(v.begin(), v.end());
    //s.reverse();
    std::reverse(s.begin(), s.end());

    show (v);
    show (s);

	return 0;
}
