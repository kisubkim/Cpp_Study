#include <iostream>
#include <thread>
#include <atomic>

constexpr std::size_t cnt = 1'000'000;
//* atomic
std::atomic<int> x = 0;			// ++, + 등을 연산자로 재정의 ==> atomic_fetch_add() 등의 함수로 구현. 

//int x = 0;

void foo()
{
	for ( int i = 0; i < cnt; i++)
	{
		x.fetch_add(5);

		// mcv eax, x
		// add eax, 1
		// mov x, eax

		//^ 1. thread safe 하게 할려면 mutex 사용하면 안전. (lock 사용)
		//^ ==> +1 때문에 lock 은 성능저하가 너무 큼.
		//^ 2. CPU 가 제공하는 multicore 에 안전하게 1증가하는 함수 사용
		//^ ==> OS lock x, CPU lock O
//		lock inc x;		//* lock-free : CPU 에서 제공하는 기능.
		//atomic_fetch_and_add(&x);		// 요런게 있기는 함.
	}
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);
	std::thread t3(&foo);
	t1.join();
	t2.join();
	t3.join();
	std::cout << x << std::endl;
}
