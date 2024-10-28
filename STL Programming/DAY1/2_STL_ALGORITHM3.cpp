#include <iostream>

// Step 3. 검색 구간의 일반화
// 함수 이름 : strchr => find
template<typename T>
T* find(T* first, T* last, int c)
{
	while (first != last && *first != c)
		++first;
	return first == last ? nullptr : first;
}

int main()
{
	double x[10]{1,2,3,4,5,6,7,8,9,10};

    // 주의 : 10개 배열의 마지막은 x+9, 하지만 x+9 넣으면 마지막 요소 검색x, 그래서 x+10 입력
    double *p=find(x, x+10, 5.0);

	if (p == nullptr)
		std::cout << "not found" << std::endl;
	else
		std::cout << "found : " << *p << std::endl;
}
