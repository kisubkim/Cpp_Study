#include <iostream>
#include <string>
#include "show.h"
/*
template< typename CharT,
    	  typename Traits = std::char_traits<CharT>,
          typename Allocator = std::allocator<CharT>> 
class basic_string
{
	CharT* buff;
public:
	bool operator==(const basic_string& other)
	{
		return Traits::compare(buff, other.buff);
	}
};
using string = basic_string<char>;
*/

//^ string에서 compare 만들 때 --> static function 으로!

//? basic_string 에 전달할 문자열 비교 정책을 만들어 봅시다
//  ==> 단위전략 class는 "지켜야할 규칙" 이 있음.
//  ==> cppreference.com에서 basic_string 검색.

// cppreference 에서 예제 가져옴.
struct ci_char_traits : public std::char_traits<char>
{
    static char to_upper(char ch)
    {
        return std::toupper((unsigned char) ch);
    }
 
    static bool eq(char c1, char c2)
    {
        return to_upper(c1) == to_upper(c2);
    }
 
    static bool lt(char c1, char c2)
    {
         return to_upper(c1) < to_upper(c2);
    }
 
    static int compare(const char* s1, const char* s2, std::size_t n)
    {
        while (n-- != 0)
        {
            if (to_upper(*s1) < to_upper(*s2))
                return -1;
            if (to_upper(*s1) > to_upper(*s2))
                return 1;
            ++s1;
            ++s2;
        }
        return 0;
    }
 
    static const char* find(const char* s, std::size_t n, char a)
    {
        const auto ua{to_upper(a)};
        while (n-- != 0) 
        {
            if (to_upper(*s) == ua)
                return s;
            s++;
        }
        return nullptr;
    }
};

// 
using ci_string = std::basic_string<char, ci_char_traits>;

int main()
{
	// std::string s1 = "ABCD";
	// std::string s2 = "abcd";

	ci_string s1 = "ABCD";
	ci_string s2 = "abcd";

	if ( s1 == s2 )
	{
		std::cout << "same" << std::endl;
	}
	else 
	{
		std::cout << "not same" << std::endl;
	}
}