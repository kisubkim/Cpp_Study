// 1_STL_PREVIEW1
#include <iostream>
#include <list>
#include <vector>

int main()
{
	// 컨테이너 : 여러개 요소 보관하는 자료구조.
	vector<int> x[5] = {1,2,3,4,5};	// 모든 요소, 연속 메모리
	// vector의 경우 중간에 삽입할 때, 뒤의 것들 모두 이동 필요. 성능 이슈

	std::list<int> s = {1,2,3,4,5};	// 모든 요소 떨어진 메모리
	// c++는 표준 버젼 Up -> 이전 내용 변경 x -> 계속 추가되는 개념.

	// 17 부터는 type 생략, 등호 생략 가능.
	vector v2 = {3,4,5,6,};
	vector v3{4,5,5,6,7};
	// 위에처럼 생략해서도 많이 사용되고 있음.

}
