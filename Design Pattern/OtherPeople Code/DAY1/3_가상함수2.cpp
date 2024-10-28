#include <iostream>

class Base
{
public:
	// ~Base() {}
	virtual ~Base() {
		std::cout << "~virtual Base() 자원해지" << std::endl;
	}
};
class Derived : public Base
{
public:
	Derived()  { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{
	// Derived d;

	// Derived* p1 = new Derived;
	// delete p1;

	Base* p2 = new Derived; // 자원 해지가 안된다. virtual 소멸자여야 될 것. 모든 기반 클래스의 소멸자는 반드시 virtual - 그것도 명시적으로. 호불호있는게 아니라 논리적으로 반드시 넣어야 함.
	delete p2;

	//가상함수가 하나도 없는 클래스에서 소멸자를 넣어야 할 때. 이렇게 한다.
}	
