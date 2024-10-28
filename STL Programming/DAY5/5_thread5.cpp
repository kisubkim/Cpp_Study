// async - 4번 복사
#include <iostream>
#include <thread>
#include <future>
#include <chrono>
using namespace std::literals;

// promise & future

// 스레드를 고려 하지 않은 함수
int add1(int a, int b)
{
	int s = a + b;
    std::cout << std::this_thread::get_id() << std::endl;
	return s;
}

int main()
{
	// std::async  : thread를 고려하지 않은 일반함수 (결과를 반환값으로 알려주는) 를 thread로 수행하고 결과를 얻을 때 사용.
    std::future<int> ft = std::async(&add1, 1, 2);
    std::future<int> ft1 = std::async(&add1, 1, 2);
    std::future<int> ft2 = std::async(&add1, 1, 2);

    std::future_status s = ft.wait_for(2s); // 2초 동안 기다림.
    if ( s == std::future_status::timeout) 
	{ 
	 
	} else if ( s == std::future_status::ready ) 
	{ 
		int ret = ft.get(); 
		std::cout << ret << std::endl; 
	} 

}
//^ std::async   : 내부적으로 아래 2개를 사용해서 만들어진 편의 함수.
//^                 ==> 단, 대부분의 compiler 구현시, Thread pooling 기술로 구현해서 성능도 좋음.
//^ std::promise : thread 간 결과를 꺼내는 도구
//^ std::thread  : C++에서 thread를 생성하는 유일한 방법
