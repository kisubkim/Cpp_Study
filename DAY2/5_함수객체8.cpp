#include <iostream>
#include <algorithm>
#include <vector>

bool cmp(int a, int b) { return a < b; }

int main()
{
	std::vector<int> v = { 1,3,5,7,9,2,4,6,8,10 };

	// #1. 비교정책을 전달하지 않으면 오름 차순
	std::sort(v.begin(), v.end());

	// #2. 비교 정책을 교체하는 방법.
	// 2.1 일반함수 사용 - 인라인 치환 X
	std::sort(v.begin(), v.end(), cmp);

	// 2.2 함수객체 사용 - 인라인 치환 O
	std::less<int> f1;			// 이미 C++ 표준(<functional>)에 있음. c++98 부터 제공
	std::sort(v.begin(), v.end(), f1);
	std::sort(v.begin(), v.end(), std::less<int>());
	//& less를 한번만 사용할 때는 임시객체 형태로 사용하는게 좋음.

	std::less<int> f2;		// 이름있는 객체. {}을 벗어날 때까지 사용 가능
	std::less<int>();		//* 이름이 없는 객체 (임시객체). 다음 문장 실행전에 파괴 (temperary instance)

	// 2.3 Lambda 사용
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;});
	std::sort(v.begin(), v.end(), [](int a, int b) { return a < b;});

	// 함수객체와 lambda는 거의 동일한 시간(성능)이 나옴
}









