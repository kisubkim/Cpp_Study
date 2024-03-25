#include <iostream>
#include <algorithm> // 이 안에 find()가 구현되엉 있음.

// Step 5. 검색실패시 반환값
// -> 0 대신 last
// 장점 1. 활용도, 부분검색 실패시, last는 다름 구간의 시작
// 장점 2. find 만들기가 쉬워지고 빨라짐.

// 구간의 표현 : 반드시 포인터일 필요는  x
// 구간의 이동 : 전위형 ++ 연산자 사용
// 검색 실패시 : last 반환

template<typename T, typename T2>
T* find(T* first, T* last, T2 c)
{
	while (first != last && *first != c)
		++first;
	return first;
}

int main()
{
	double x[10]{1,2,3,4,5,6,7,8,9,10};

    double *p=find(x, x+10, 5);
    double *p2 = std::find(x, x+10, 5);

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p2 << std::endl;
}
