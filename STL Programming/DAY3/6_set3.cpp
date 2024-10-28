// policy base design
#include <iostream>
#include "show.h"

#include <set> // Red Black Tree로 구현

//& == 연산은 비교할 때 사용 X, 비싼 연산자.
/*
// set의 템플릿 인자
template<typename T,        // 저장할 타입
         typename Pr = std::less<T>,    // element compare에 사용할 함수객체
         typename Ax = std::allocator<T>>
class set {
    Ax ax;      // memory allocator
    Pr cmp;     // 요소 비교를 위한 함수 객체
    public:
        void insert(const T& e)
        {
            if (cmp(root, e))
                add right_child;
            else if (cmp(e, root))
                add left_child;
            else
                return 실패;    // pair type으로 리턴해야함.
                
        }
};
*/

int main()
{
	std::set<int, std::greater<int>> s;            // 기본적으로 cmp 연산은 < (std::less) 임

	s.insert(20);
	s.insert(30);
	s.insert(15);
	s.insert(5);
	s.insert(40);
	s.insert(17);
	s.insert(25);

	auto first = s.begin();		// 가장 왼쪽의 Node
	auto last  = s.end();		// 오른쪽 마지막 다음 Node

	while (first != last)
	{
		std::cout << *first << std::endl;
		++first;
	}
	
}







