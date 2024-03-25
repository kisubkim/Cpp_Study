//* algorithm 5번 복사해오기

#include <iostream>

// Step 5. 검색실패시 반환값

// 일반함수를 만들 때, 가능하면 알아보기 좋은 형태로 변경을 하는 것이 좋음.
//* Algorithm이 요구하는 Iterator category 를 알려주는 것이 관례
// template 선언할 때, class와 typename은 동일함.
template<typename InputIter, typename T>
InputIter find(InputIter first, InputIter last, const T& c)
{
	while (first != last && *first != c)
		++first;
	return first;
}

int main()
{
	double x[10]{1,2,3,4,5,6,7,8,9,10};

    double *p=find(x, x+10, 5);

	
}
