#include <vector>
#include <algorithm>
#include "show.h"

int main()
{
	int x[10] = { 1,2,3,4,5,6,7,8,9,10 }; 
	std::vector<int> v = { 1,2,3,4,5,6,7,8,9,10 }; 

	// array, vector는 memory struct가 유사. (연속된 memory)
	//^ 가장큰 차이는 memory의 위치. array는 stack, vector는 heap
	x[0] = 10;
	v[0] = 10;

	for(int i = 0; i < 10; i++) {
		int x1[10];			// 이게 더 빠르기는 함. (stack은 연속된 memory 사용)
		std::vector<int> v1(10);	// vector는 heap에서 공간을 찾아야함. -> 느림. 생성이
	}
	//^ memory allocate speed는 array가 빠르고, vector는 느림.
}
