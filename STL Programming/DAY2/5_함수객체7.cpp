// 3_함수객체7 - 136 page소스
#include <iostream>
#include <algorithm>

inline bool cmp1(int a, int b) { return a < b; }
inline bool cmp2(int a, int b) { return a > b; }
struct Less   { inline bool operator()(int a, int b) { return a < b; }};
struct Greater{	inline bool operator()(int a, int b) { return a > b; }};

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };

	//^ C++ 표준 sort()는 모든 인자가 템플릿.
	// => 사용자가 사용하는 형태에 맞게 code 생성됨을 의미.

	// 1. 비교 정책으로 일반함수 사용시
	//^ 장점 : 비교 정책을 여러번 교체해도 sort() 함수는 한개만 생성 => code memory 사용량 감소
	//& 단점 : 비교 정책을 담은 함수가 치환이 되지 않음. (assemble(기계어)로 만들 때 바꿀 수 없음.) --> 느림
	std::sort(x, x + 10, cmp1);		// (int*, int*, bool(*)(int, int)) 인 함수 생성
	std::sort(x, x + 10, cmp2);		// (int*, int*, bool(*)(int, int)) 인 함수 생성 (같은 type) -> 생성되는 함수는 동일

	// 2. 비교정책으로 함수객체 사용시
	//^ 장점 : 비교 정책이 인라인 치환됨. --> 빠름
	//& 단점 : 정책을 교체한 횟수만큼의 sort() 함수 생성 -> code memory 사용량 증가
	Less    f1;
	Greater f2;
	std::sort(x, x + 10, f1);		// (int*, int*, Less) 인 함수 생성
	std::sort(x, x + 10, f2);		// (int*, int*, Greater) 인 함수 생성
}









