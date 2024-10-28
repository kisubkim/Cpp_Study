#include <iostream>
#include <string>
#include "show.h"

//^ STL string 은 "SSO" 사용
//^ ==> SSO : Small String Optimization
//^ string length가 작으면 (16이하) 그냥 heap을 가리키는 곳에 저장하고
//^ length가 더 크면 heap 할당해서 그곳에 넣음.

using dstring = std::basic_string<char, std::char_traits<char>, debug_alloc<char>>;

int main()
{
	for(int i = 0; i < 20; i++)
	{
		std::cout << i << std::endl;
		dstring s(i, 'A');		// 'A' 글자를 i번 넣음.
		//std::cout << s.data() << std::endl;
	}
}