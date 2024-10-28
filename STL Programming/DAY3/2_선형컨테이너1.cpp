// 6_선형컨테이너(sequence container)
// memory 상에서 0---0----0---0--0, 선형
//^ 알아야 할 것들
//^ 1. Memory 구조
//^ 2. Iterator type 
// C++98 에서 3개
#include <vector>  // 연속된 메모리, 임의접근 반복자
#include <deque>   // 연속된 메모리와 유사, 임의접근 반복자
#include <list>    // 떨어진 메모리, 양방향 반복자

// C++11 추가된 2개
#include <forward_list> // 전진형 반복자
#include <array>		// 임의접근 반복자

#include "show.h"

int main()
{
	// 선형 컨테이너 는 사용법의 거의 동일 합니다.
	std::list<int> s = { 1,2,3 };
	std::vector<int> v = { 1,2,3 };
	std::deque<int> d = { 1,2,3 };

	s.push_back(5);
	v.push_back(5);
	d.push_back(5);

	//& 사용법이 다르다? ==> 의도적 설계

	s.push_front(5); 
	//v.push_front(5);		// error, continuous memory, 앞에 추가 처리량 많음 <--제공X 이유.
	d.push_front(5);

	//^ [] operator, list x
	//s[0] = 0;		// error <- 무조건 처음부터 이동. 
	v[0] = 0;		
	d[0] = 0;

	// [] 필요, 전방삽입 필요 x : vector
	// [] 필요, 전방삽입 필요 o : deque
	// 삽입삭제 많다 : list
	//& 일반적 상황에서는 vector 권장.
	// 삽입삭제가 많아도 vector가 cash를 미리 접해놓기 때문에 크게 차이 없음.

}
