// static_factory_method1.cpp
#include <iostream>

// static factory method
// => "new 클래스 이름" 하지말고 "static 멤버 함수"로 객체를 생성하게 하라는것

class Window
{
public:
	Window() {  }

	virtual void init() { std::cout << "1. Window init\n"; }

	template<typename T>
	static T* create()
	{
		T* p = new T; // 먼저 만들고
		p->init();    // 초기화 함수까지 호출하고

		return p;	  // 반환. 
	}
};



class MyWindow : public Window
{
	int data;
	MyWindow() : data(99) {}
public:
	void init() override { std::cout << "2. MyWindow init\n"; int n = data; }
	
	friend class Window;
};

int main()
{

	MyWindow* w = Window::create<MyWindow>(); 
}