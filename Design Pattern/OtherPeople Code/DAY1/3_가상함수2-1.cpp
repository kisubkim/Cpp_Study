#include <iostream>

class Base
{
public:
	
protected: 
	~Base() {
		std::cout << "~Base() 자원해지" << std::endl;
	}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() 자원할당" << std::endl; }
	~Derived() { std::cout << "~Derived() 자원해지" << std::endl; }
};
int main()
{

	//그러나 가상함수를 쓰면 느리고, 가상 함수 table로 인한 오버헤드가 발생하게된다.

	//또 다른 해결책 - protected 소멸자. -> 외부에서 그냥 protected로 소멸자를 못쓰게 해버리면 된다
	Base* p = new Derived; 
	//delete p;  // error

	delete static_cast<Derived*>(p);
	// 소멸자가 가상이 아니므로 사용자가 주의해서 사용하라는 것이다.
}
