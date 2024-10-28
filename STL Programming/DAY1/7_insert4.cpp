#include <iostream>
#include <list>

template<typename T>
class my_back_insert_iterator {
        T* cont;
    
    public:
        constexpr my_back_insert_iterator(T& c) : cont(&c) {}

        constexpr my_back_insert_iterator& operator*() { return *this; }
        constexpr my_back_insert_iterator& operator=( const typename T::value_type value) {
            cont->push_back(value);
            return *this;
        }
};

int main()
{
    std::list<int> s{1,2,3};

    my_back_insert_iterator< std::list<int> > p(s);

    *p = 10;    // s.push_back(10)
}