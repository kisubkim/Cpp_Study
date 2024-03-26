// 3_알고리즘과정책변경
#include <iostream>
#include <vector>
#include <algorithm>	// 정렬, 검색 등의 Algorithm
#include <numeric>    // 수치 관련 연산 (합, 부분합, 내적, etc.)
#include <functional>
#include "show.h"

int main()
{
	std::vector<int> v1 = { 1,2,3,4,5,6,7,8,9,10 };

	//std::sort(v1.begin(), v1.end());		// Algorithm header에 있는 녀석

	// 1. numeric 에는 다양한 수학관련 알고리즘이 있음.
	//int n = std::accumulate(v1.begin(), v1.end(), 0);		// 기본 ver은 + 사용

	//^ 2. STL은 많은 Algorithm 의 "정책변경"이 가능
	//int n = std::accumulate(v1.begin(), v1.end(), 0, [](int a, int b){ return a*b;});	// 요렇게 하면 내 람다식으로 0부터 곱하는 거임.
	//int n = std::accumulate(v1.begin(), v1.end(), 1, [](int a, int b){ return a*b;});	// 1부터 곱하는 거임.

	//* +, -, *, /, % 등의 연산을 수행하는 함수객체가 이미 있음.
	int n = std::accumulate(v1.begin(), v1.end(), 1, std::multiplies<int>());	// 
	std::cout << n << std::endl;

}
