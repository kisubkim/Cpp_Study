#include <stack>
#include <list>
#include <queue> // queue, priority_queue
#include "show.h"

int main()
{
	// 다음중 에러를 모두 골라 보세요
	// stack : 한방향 접근
	// queue : 두방향 접근, vector는 앞쪽이 막혀 있음.

	std::stack<int, std::list<int>>   s1;
	std::stack<int, std::vector<int>> s2;
	std::stack<int, std::deque<int>>  s3;

	std::queue<int, std::list<int>>   q1;
	std::queue<int, std::vector<int>> q2;		// error (제 생길 거임), pop()없으면 compile 자체는 됨.
	std::queue<int, std::deque<int>>  q3;

	q2.push(0);
	//q2.pop();		// error. 내부적으로 vector.pop_front() 호출
}



