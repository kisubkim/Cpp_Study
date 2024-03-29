#include <iostream>
#include <string>
#include "show.h"

//^ STL: Standard Template Library

/*
template< typename CharT,
    	  typename Traits = std::char_traits<CharT>,
          typename Allocator = std::allocator<CharT>> 
class basic_string
{
};
using string = basic_string<char>;
using wstring = basic_string<wchar_t>;		//^ unicode 사용하겠다.
*/

//^ string 은 별명이고, 진짜 이름 basic_string<char>
int main()
{
	std::string s = "hello";
	std::wstring ws = L"test";		// unicode 사용시에 L prefix 사용.
}