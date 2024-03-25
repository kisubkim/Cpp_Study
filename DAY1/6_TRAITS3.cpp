#include <iostream>
#include <list>

// 아래 code는 이미 c++ 표준에 구현되어 있음.
template<typename T> struct iterator_traits {
    using value_type = T::value_type;
};

// T가 raw pointer인 경우를 위해서 "템플릿 부분 특수화 문법" 사용
template<typename T> struct iterator_traits<T*> {
    using value_type = T;
};

//위에 구현한 걸 써도 되지만, std 사용하는 것도 좋음.
// auto 도 사용이 가능하지만, error 가 발생할 가능성이 있음. 따라서 명시적으로 적어 주는 것이 아주 좋음.
// 현재 기법은 overhead가 없음.

template<typename T>
typename std::iterator_traits<T>::value_type sum(T first, T last){

    // 둘다 T의 value_type을 꺼낸 건데...단지 처음꺼는 direct로 가져온거고, 두번째 거는 traits를 한번 거친거.
	//typename T::value_type s = 0;
    typename std::iterator_traits<T>::value_type s = 0;      // 여기서 T는 int*를 보내고 있음. (현재 code에서)
	while (first != last){
		s += *first;
		++first;
	}
	return s;
}

int main()
{
    // "raw pointer" 도 Iterator 이기 때문에 아래 처럼도 사용이 가능해야함.
    int x[10] { 1,2,3,4,5,6,7,8,9,10 };
    int n = sum(x, x+10);

	std::cout << n << std::endl; // 55
}
