
#include <iostream>
#include <vector>
#include <list>

// container 내부 값을 바꿀려면 &, 아니면 const &
template<typename C>
void container_element_type(C& c){
    // C : std::vector<int>

    // C가 저장하는 type을 알고 싶다면
    typename C::value_type n;

    std::cout << typeid(n).name() << std::endl;
}

// Iterator는 크키가 작은 타입이라 call by value가 관례
template<typename T>
void iterator_element_type(T c){
    // C : std::vector<int>

    // T가 저장하는 type을 알고 싶다면
    //typename T::value_type n;    // 단, 이 code는 T가 raw pointer라면 error 임.
    //따라서 아래처럼 변경 필요
    typename std::iterator_traits<T>::value_type n1;

    // C++20부터는 더 간단해짐.
    std::iter_value_t<T> n2;

    std::cout << typeid(n2).name() << std::endl;     


    

}


int main()
{
    std::vector<int> v{1,2,3};
    container_element_type(v);
    iterator_element_type(v.begin());
}