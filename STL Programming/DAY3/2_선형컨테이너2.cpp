
#include <vector>
#include <iostream>
#include <algorithm>
#include "show.h"

int main()
{
	// 1. 생성
	std::vector<int> v1;
	std::vector<int> v2(10);		// 10개, 0으로
	std::vector<int> v3(10, 3);		// 10개, 3
	std::vector<int> v4(v3);		// v3과 동일. 복사생성자
	std::vector<int> v5{ 10, 3 };	// 2개를 10, 3
	std::vector<int> v6 = { 1,2,3 };	// 3개를 1, 2, 3
	

	// 2. 삽입, 
	v1.push_back(0);
	v1.push_front(0);			// 전방삽입, vector는 X
	v1.insert(위치 반복자, 0);	// Iterator 앞에 삽입

	// 3. 접근
	int n1 = v1.front();
	int n2 = v1.back();
	int n3 = v1[1];			// list X
	int n4 = v1.at(1);		// list x

	// 4. 요소 제거
	v1.pop_back();
	v1.pop_front();		// vector X

	v1.erase(반복자A);				// iterator 위치 제거
	v1.erase(반복자A, 반복자B);		// range

	// 5. element 전부 교체
	v1.assign(v2.begin(), v2.end());		// v1 = v2의 의미. assign은 다른 container도 가능
											// => 인자로 전달되는 iterator는 모든 container 가능
											// => vector에 다른 container의 element 넣을 때 사용 

}
