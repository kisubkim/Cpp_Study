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