#include <iostream>
#include <thread>
#include <mutex>

//^ stack : thread 당 1개
//^ heap, data memory, code memory : process 당 1개 (모든 thread 가 공유)
//& GUI는 thread 소속임. thread 죽으면 GUI 도 맛감.
//& file pointer 같은 건 보통 process 소유임.

std::mutex m;
int shared_data = 10;		// file 같은 작업이라고 가정.

void foo()
{
	int data = 0;

	// 공유 자원 사용	
	m.lock();
	shared_data = 200;
	m.unlock();
}

int main()
{
	std::thread t1(&foo);
	std::thread t2(&foo);

	t1.join();
	t2.join();
}

