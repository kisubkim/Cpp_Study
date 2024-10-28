#include "show.h"
#include <stack>
#include <vector>
#include <list>

int main() {
	
	//std::stack<int> s;
	//std::stack<int, debug_alloc<int>> s; // error, stack 자체에 할당기 없음. 2st 인자는 container.
	std::stack<int, std::vector<int, debug_alloc<int>>> s;

	s.push(0);		// 이 순간 메모리 할당 정보를 볼 수 있도록
					// 위 모트데 allocator 를 변경해보세요. debug_alloc으로
}