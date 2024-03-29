#include <iostream>
#include <thread>
#include <future>
#include <chrono>
#include <future>

using namespace std::literals;
//^ 반환값 받는 방법
//^ 1. out parameter 이용
//^		==> join() 해야만 이용이 가능. 즉, thread 종료 필요.
//^ 2. promise & future

// 1. thread function 은 arg 로 prosmise 참조를 받아야함.
void add(int a, int b, std::promise<int>& p)
{
	try
	{
		/* code */
		int s = a + b;
		
		// 연산이 종료되면 promise 객체를 통해서 main thread에 알려줌.
		p.set_value(s);		// 이 순간 대기중인 main thread 가 깨어남.
	}
	catch(const std::exception& e)
	{
		// promise 는 예외전달도 가능.
		p.set_exception(std::current_exception());
	}
	
	// 이후 나머지 정리 작업.....
	std::this_thread::sleep_for(2s);
}

int main()
{
	// thread 생성 시
	// 1. promise 만들고
	// 2. promise 안에서 미래의 결과를 담은 future를 꺼냄.
	std::promise<int> p;
	std::future<int> ft = p.get_future();

	// 3. thread 생성시 promise 의 참조를 인자로 전달.
	std::thread t(&add, 1, 2, std::ref(p));		// method 1

	std::cout << "다른 작업을 하다가.." << std::endl;

	try
	{
		// 4. 결과가 필요하면 future 를 통해서 꺼내면 됨.
		int ret = ft.get();		// 결과가 나올때까지 대기.
		std::cout << ret << std::endl;
	}
	catch(...)
	{
		// thread 에서 예외가 발생하면..여기서 exception을 받을 수 있음.
		// thread function 에서 p.set_exception(std::current_exception()) 요거 한 부분
	}
	
	

	t.join();
}
