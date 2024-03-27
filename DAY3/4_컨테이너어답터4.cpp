#include <stack>
#include <queue> // queue, priority_queue
#include <iostream>
#include "show.h"

int main()
{
	// 우선순위큐 : 요소를 꺼낼때 우선순위가 가장 높은
	//			요소가 나오게 된다.
	//^ 즉, 들어간 순서가 아닌 element의 우선순위(<= 가 default) 순으로 나옴. Heap algorithm 사용.
	//std::priority_queue<int> pq;
	std::priority_queue<int, std::vector<int> ,std::greater<int>> pq;
	pq.push(10);
	pq.push(-10);
	pq.push(-20);
	pq.push(20);
	pq.push(15);

	std::cout << pq.top() << std::endl; 		// 20
	pq.pop();
	std::cout << pq.top() << std::endl; 		// 15

}



