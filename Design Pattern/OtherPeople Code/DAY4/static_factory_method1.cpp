// static_factory_method1.cpp
#include <iostream>

// �ٽ� #1. �����ڿ����� �����Լ��� �������� �ʽ��ϴ�. 
//			�����ڿ��� �����Լ� ȣ������ ������ - ���� �Դϴ�.

// �ٽ� #2. �� �̷� ������ ��������� ?
// => ���� �Ʒ� �ڵ尡 MyWindow::init() �� ȣ���ߴٸ�
// => �ʱ�ȭ ���� ���� ��� ����Ÿ(data) �� ����ϰ� �˴ϴ�.
// => �׷���, "�����ڿ����� �����Լ�"�� �������� �ʽ��ϴ�.

class Window
{
public:
	Window() { init(); }	// 1�� ȣ��

	//	void foo() { init(); } // 2 �� ȣ��

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
// �������� ����, ��� ������ ������