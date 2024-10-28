#include <iostream>
#include <thread>
#include <mutex>

std::mutex m;
int shared_data = 10;

// 자원의 해지는 항상 소멸자를 통해서 하는게 좋음. //* 자원의 해지는 함수 끝이 아닌 처음에 등록한다.
//^ 내려가는 동안 무슨 일이 생길지 알 수없음.

//^ stack unwinding : 지역변수는 안전하게 파괴됨을 보장.
//& RAII : Resource Acquisition Is Initialization
//& ==> 자원의 획득은 (자원관리객체)가 초기화 될 때이다.
//& ==> 생성자에서 획득, 소멸자에서 반납하도록 하라.

template<typename T>
class lock_guard {
	T& mtx;
	public:
	lock_guard(T& m) : mtx(m) { mtx.lock(); }
	~lock_guard() { mtx.unlock(); }
};

void foo()
{
	{		// block 안에서는 lock() 이 해제되는 것을 보장.
		lock_guard<std::mutex> g(m);		// 핵심임. //& STL 에서 제공함. std::lock_guard
		shared_data = 200;	
	}
}

//^ c++ standard의 lock management 4개
//^ 1. std::lock_guard - 기본, 권장
//^ 2. std::unique_lock - 많은 기능, 무거움
//^ 3. std::shared_lock - shared-mutex 적용
//^ 4. std::scoped_lock - 2개 이상의 metext 동시에 lock. (deadlock 피하고자 할때, 동시에 lock 잡을 때)

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

