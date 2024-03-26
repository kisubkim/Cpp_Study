#include <iostream>
#include <list>
#include <algorithm>

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,3,9,10};

	//auto p1 = s.begin();		// begin(), end() 는 항상 iterator 반환하는 것 잊지 말 것.
	//auto p2 = s.end();		// 10 다음을 가리킴.

    // 아래 답을 위한 첫번째
    // auto p1 = std::make_reverse_iterator(s.end());		// begin(), end() 는 항상 iterator 반환하는 것 잊지 말 것.
	// auto p2 = std::make_reverse_iterator(s.begin());		// 10 다음을 가리킴.

    // 아래처럼 쉽게 할 수도 있음. 요것도 언제부터 제공되었을 라나..ㅎ
    //* 중간에서부터 reverse iterator 사용할려면 위쪽의 방법을 써야함.
    auto p1 = s.rbegin();
    auto p2 = s.rend();

    // 실행해 본 후에, 아래 코드는 변경하지 말고, 거꾸로 출력을 하려면
    // 위를 어떻게 수정해야 하는가?
	while( p1 != p2)
	{
        std::cout << *p1 << ", ";
        ++p1;
    }
}
