#include <iostream>

// Step 4. 보다 일반화(유연)되도록 
// 구간의 type과 변수의 type은 분리 필요

// 아래처럼 만들면 2개의 단점이 있음.
// 1. 구간의 타입과 검색 요소 타입이 연관됨
// ==> double 배열에서 int 검색 x
// 2. T*라고 표기하면 구간은 항상 raw pointer만 가능
// ==> smart pointer 사용 x


// 아래처럼 만들면
// 1. 구간과 검색요소 타입이 분리
// 2. 구간은 반드시 raw poinnter 일 필요가 없음.
// => 단, 구간을 나타내는 type은 ++, --, ==, !=, * 연산 가능해야함.
template<typename T, typename T2>
T* find(T* first, T* last, T2 c)
{
	while (first != last && *first != c)
		++first;
	return first == last ? nullptr : first;
}

int main()
{
	double x[10]{1,2,3,4,5,6,7,8,9,10};

    double *p=find(x, x+10, 5);

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
