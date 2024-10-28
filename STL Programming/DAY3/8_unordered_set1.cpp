#include <iostream>
#include <unordered_set>
#include "show.h"
// data 량이 많으면 tree
// data 량이 적으면 hash

// hash 함수

int main()
{
    // c++ 표준 hash 함수는 함수 객체(템플릿) 임.
    std::hash<int> hi;
    std::hash<double> hd;
    std::hash<std::string> hs;

    std::cout << hi(100) << ", " << hi(100) % 13 << std::endl;
    std::cout << hd(3.4) << ", " << hd(3.4) % 13 << std::endl;
    std::cout << hs("ABC") << ", " << hs("ABC") % 13 << std::endl;
    std::cout << hs("XYZ") << ", " << hs("XYZ") % 13 << std::endl;
    std::cout << hs("aaa") << ", " << hs("aaa") % 13 << std::endl;
}

