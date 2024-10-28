#include <iostream>
#include <thread> 
#include <string>

class Test
{
public:
	void goo(int n, double d)
	{
		std::cout << "goo" << std::endl;
	}
};

void f1() { }
void f2(int a, double d) { }
void f3(int a, int& b, std::string&& s) { b = 100; }

//& 주 thread 가 부 thread 종료까지 대기하거나 완전히 둘을 분리해야 error 안남.

int main()
{
	// #1. thread 생성
	//f1();
	std::thread t(f1);		//^ new thread 생성해서 f1 함수 실행.
							//^ 따로 start 없이 객체 생성하면 바로 실행.

	// 쓰레드를 생성하면
	// 1. 종료 대기 (join)
	// 2. 떼어 내기 (detach
	t.join();		// thread 종료 대기. 여기서 계속 대기. ==>  C++ 에서는 관례적으로 join() 사용.
					//& 여기까지 thread 가 종료되어야 할 때 많이 사용
	//t.detach();		// thread 떼어 내기

	//^ C++ thread 는 background thread 임. (즉, 주 thread가 죽으면 부 thread 다 죽음.)
	//^ foreground는 주 thread 가 죽어서 계속 진행함.

	// #2. 인자 전달
	std::thread t2(&f2, 3, 2.1);

	int n = 0;
	std::string a = "aa";

	std::cout << a << std::endl;
	std::thread t3(&f3, std::ref(n), std::move(a));
	std::cout << a << std::endl;

	t2.join();
	t3.join();

	//^ 멤버함수를 thread 로 수행하려면 객체도 같이 전달.
	Test test;
	std::thread t4(&Test::goo, &test, 1, 3.2);
	t4.join();
}


