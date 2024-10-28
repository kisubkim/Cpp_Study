#include <iostream>
#include <vector>
#include <thread>

template<typename T> 
void foo(T a) {}

int main()
{
	// foo 를 호출
	foo(3);

	// #1. foo 를 스레드로 실행해 보세요
	//std::thread t1(&foo, 3);		//& error, foo 가 template으로 찍어내서, T를 알 수가 없음.
	std::thread t1(&foo<int>, 3);
	t1.join();

	// #2. thread 객체의 copy 와 move
	std::thread t2(&foo<int>, 3);
	//std::thread t3 = t2;			//& error. std::thread 의 copy constructor 가 delete. 이게 먼말?
	std::thread t4 = std::move(t2);	//ok
	
	// 3. thread object를 먼저 만들고 나중에 thread 생성.
	std::thread t5;

	t4 = std::thread(&foo<int>, 3);		//* 우변이 임시객체. 임시객체는 자동으로 move.

	//^ 4. 여러개의 thread를 vector로 관리하는 기술
	std::vector<std::thread> v(10);		// 10개 미리 생성.
	v[0] = std::thread(&foo<int>, 3);
	v[1] = std::thread(&foo<int>, 2);
	v[2] = std::thread(&foo<int>, 6);

	t5.join();
	v[0].join();
	v[1].join();
	v[2].join();
}