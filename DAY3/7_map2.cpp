#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <list>
#include <map>
#include <algorithm>
#include "show.h"
// 특정 file 검색해서, 어떤 단어가 어디에 있는지 찾기
int main()
{
    std::ifstream fin("7_map2.cpp");
    std::string s;
    int no = 0;

    // key 한개에 여러개의 data를 넣고 싶다면 container 를 data쪽에 넣으면 됨
    std::map<std::string, std::vector<int>> index;      // 핵심. 자료구조 생각해보자.
    // 이제 coding 시작.
    std::string word;
    while(std::getline(fin, s))
    {
        ++no;

        std::istringstream iss(s);
        while( iss >> word){
            index[word].push_back(no);
        }
    }

    for(const auto& [key, value]:index)
    {
        std::cout << key << " : ";
        show(value);
    }
}


