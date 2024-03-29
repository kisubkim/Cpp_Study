#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;
//^ 반환값 받는 방법
//^ 1. out parameter 이용
//^		==> join() 해야만 이용이 가능. 즉, thread 종료 필요.


void add(int a, int b, int& s)
{
	s = a + b;

	// method 1 의 상황에서 뒤에 자원 정리작업이 있을 경우
	std::this_thread::sleep_for(2s);
}

int main()
{
	int ret = 0;
	std::thread t(&add, 1, 2, std::ref(ret));		// method 1

	t.join();

	std::cout << ret << std::endl;
}
