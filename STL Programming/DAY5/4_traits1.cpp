﻿// 4_traits
#include <iostream>

// STL에서 C++11부터 제공
template<typename T> void printv(const T& v)
{
	if ( T가 포인터 타입이라면 )
		std::cout << v << " : " << *v << std::endl;
	else
		std::cout << v << std::endl;
}

int main()
{
	int n = 10;
	double d = 10;

	printv(n);
	printv(d);
	printv(&n);
}

