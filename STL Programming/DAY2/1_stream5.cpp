#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

int main()
{
    std::ifstream fin("1_stream5.cpp");

    // 아래 반복자는 white space (공백, tab, backspace 등) 가 입력이 되지 않음.
    // std::istream_iterator<char> p1(fin);
    // std::istream_iterator<char> p2;     // default constructor 로 만들면 EOF 의미

    // 아래 반복자는 white space 입력됨.
    std::istreambuf_iterator<char> p1(fin);
    std::istreambuf_iterator<char> p2;     // default constructor 로 만들면 EOF 의미

    std::ostream_iterator<char> p3 (std::cout, "");

    std::copy(p1, p2, p3);
    
}

// 출력이 한글 깨지면 터미널(power shell)에서 "chcp 65001" 입력하면 제대로 나옴
