#include <iostream>
#include <list>

// Container::value_type : container가 저장하는 elemet's type
// Iterator::value_type : iterator가 가리키는 element's type

template<typename T>
typename T::value_type sum(T first, T last){
	typename T::value_type s = 0;
	while (first != last){
		s += *first;
		++first;
	}
	return s;
}

int main()
{
	std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };

	int n = sum(s.begin(), s.end());

	std::cout << n << std::endl; // 55
}
