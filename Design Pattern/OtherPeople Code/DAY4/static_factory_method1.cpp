// static_factory_method1.cpp
#include <iostream>

// 핵심 #1. 생성자에서는 가상함수가 동작하지 않습니다. 
//			생성자에서 가상함수 호출하지 마세요 - 버그 입니다.

// 핵심 #2. 왜 이런 문법을 만들었을까 ?
// => 만일 아래 코드가 MyWindow::init() 을 호출했다면
// => 초기화 되지 않은 멤버 데이타(data) 를 사용하게 됩니다.
// => 그래서, "생성자에서는 가상함수"가 동작하지 않습니다.

class Window
{
public:
	Window() { init(); }	// 1번 호출

	//	void foo() { init(); } // 2 번 호출

	virtual void init() { std::cout << "1. Window init\n"; }
};

class MyWindow : public Window
{
	int data;
public:
	MyWindow() : data(99) {} // MyWindow() : Window(), data(99) {}

	void init() override { std::cout << "2. MyWindow init\n"; int n = data; }
};

int main()
{
	MyWindow w;
	//	w.foo();
}
// 실행하지 말고, 결과 예측해 보세요