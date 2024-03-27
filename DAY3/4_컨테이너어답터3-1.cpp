#include <vector>

// template은 class가 아님. --> class 를 찍어내는 틀임.
// 이때, Queue라는 class에 member function이 한 100개 있다고 치면
//& 실제 template사용해서 Queue class를 선언하고 사용하면, compile 될 때
//& code 내부에서 사용된 member function만 Queue class에 포함되어 만들어짐.
//^ 지연된 인스턴스화
//^ => class template 의 member function은 "사용되는 것만 instance 로 만듬."
//^ => 그래서 사용 안하면 전체로 보면 error 라도, code에서 error로 잡히지 않음.
//^ => 가능하면 이런 사항도 고려해서 compile 시 error 로 안잡혀도 주의할 것.
template<typename T>
class Queue {
	std::vector<T> v;
	public:
		// vector에는 pop_front() 없음.
		void pop() { v.pop_front(); }
};

int main() {
	Queue<int> q;
}