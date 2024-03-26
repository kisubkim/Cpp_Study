#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <list>

template<typename T>
void show(const T& c){
    for( auto& e:c){
        std::cout << e << ", ";
    }
    std::cout << std::endl;
}

template<typename InputItr>
void show(InputItr s, InputItr e){
    std::ostream_iterator<typename std::iterator_traits<InputItr>::value_type> p1(std::cout, ", ");
    std::copy(s, e, p1);
    std::cout << std::endl;
}

int main()
{
    std::list<int> s{1,2,3,4,5,6,7,8,9,10};
    int x[10]{1,2,3,4,5,6,7,8,9,10};

    // container의 모든 내용 출력
    show(s);
    show(x);

    // 반복자 ver
    show(s.begin(), s.end());
    show(x, x+10);
}

