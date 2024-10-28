#include "show.h"
#include <queue>

template<typename T>
class PQ : public std::priority_queue<T> {

	public:
		void print() const {
			show(this->c);	// 기반 클래스인 std::priority_queue<T>가 가진 container 이름이 "c".
							//& template 사용해서 선언할 때는 this 로 접근해야 parents class member 접근 가능.
		}
};

int main() {
	PQ<int> pq;

	pq.push(10);pq.print();
	pq.push(-10);pq.print();
	pq.push(-20);pq.print();
	pq.push(20);pq.print();
	pq.push(15);
	pq.print();

	return 0;
}