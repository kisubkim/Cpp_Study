// static_factory_method1.cpp
#include <iostream>

// static factory method
// => "new Ŭ���� �̸�" �������� "static ��� �Լ�"�� ��ü�� �����ϰ� �϶�°�

class Window
{
public:
	Window() {  }

	virtual void init() { std::cout << "1. Window init\n"; }

	template<typename T>
	static T* create()
	{
		T* p = new T; // ���� �����
		p->init();    // �ʱ�ȭ �Լ����� ȣ���ϰ�

		return p;	  // ��ȯ. 
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