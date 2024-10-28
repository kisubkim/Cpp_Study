#include <iostream>
#include <algorithm> 

// 137page 아래부분

//^ 함수 인자로 비교 정책을 담은 함수를 받아서 사용
//& 이 함수는 실제로 해보면 느림. 이유는 내부에서 다시 function call을 사용하고 있어서.
//& 내부적으로 직접 비교하는 것보다는 느림.
// 장점 : 비교 정책의 교체가 됨으로 유연성이 좋음
// 단점 : 비교시 다시 함수를 호출 --> 느름
//		cmp1, cmp2를 inline으로 만들어도 "함수포인터에 담아서 사용" case라서 인라인 치환안됨.
// C 언어에서 qsort() 가 아래 cmp 사용하는 방식으로 만들었음. 결국 사용하면 X

//* 비교 정책 교체가 가능한데, 인라인 치환이 되게할려면?
//* C 언어로는 X, STL로는 O
void Sort(int* x, int sz, bool(*cmp)(int, int) )
{
	for (int i = 0; i < sz - 1; i++)
	{
		for (int j = i + 1; j < sz; j++)
		{
			// if (x[i] > x[j])		// 1
			if (cmp(x[i], x[j]) == true) 		// 2 ==> 이게 더 느림. 
				std::swap(x[i], x[j]);
		}
	}
}

// 비교 정책으로 사용할 이항 함수.
inline bool cmp1(int a ,int b) {return a > b;}
inline bool cmp2(int a ,int b) {return a < b;}
// 위의 두 함수는 "다른 함수"
// 하지만 위의 두 함수는 "같은 타입"

int main()
{
	int x[10] = { 1,3,5,7,9,2,4,6,8,10 };
	//Sort(x, 10);
}

