#include <iostream>
#include <list>


// 반복자의 형태별 분류
// 1. 1일차 오전에 만ㄴ든 slistiterator 처럼, class 문법으로 만들어진 반복자
// 2. raw pointer 도 반복자@@

// 위 2개의 차이 때문에 아래 sum() 같은 함수를 만들기 어려움.
//* => 이 문제의 해결책이 std::iterator_traits 임

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
	// std::list<int> s = { 1,2,3,4,5,6,7,8,9,10 };
	// int n = sum(s.begin(), s.end());

    // "raw pointer" 도 Iterator 이기 때문에 아래 처럼도 사용이 가능해야함.
    int x[10] { 1,2,3,4,5,6,7,8,9,10 };
    int n = sum(x, x+10);

	std::cout << n << std::endl; // 55
}
