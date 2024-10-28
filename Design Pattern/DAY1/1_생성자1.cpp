//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:						
	// 사용자 code				// compiler 가 변경하는 code
	Derived()					// Derived() : Base()
	{ std::cout << "Derived()" << std::endl; }
	Derived(int a)				// Derived(int a) : Base()		--> 컴파일러가 추가하는 code는 항상 디폴트 생성자를 호출함.	
	{ std::cout << "Derived(int)" << std::endl; }
	~Derived()		{ std::cout << "~Derived()" << std::endl; }
	// 소멸자는 "Derived 구현이 모두 실행된 후, 기반 클래스 소멸자 호출
	// Base::~Base() <--- 즉, 소멸자 모두 실행된 이후에 호출임.
};

// 개념을 잘 이해해야함. 일단 무조건 Derived가 먼저 호출은 되는게 맞기는 함. 하지만 호출된 이후에 바로 base 생성자를 호출한 다음에
// 자기 생성자의 내용을 실행함. 그래서 잘못생각하면 Base()가 먼저 호출되었다고 생각할 수 있음.
// 실행 순서는 Derived() -> Base() 가 맞음. 다만 무조건 Derived()처음에 Base()를 호출하기 때문에 Base가 먼저 호출되는 것처럼 보임.

int main()
{
	Derived d1;
//	Derived d2(5);

}
