//생성자1.cpp - 3page
#include <iostream>

class Base
{
public:
	Base() { std::cout << "Base()" << std::endl; }
	Base(int a){ std::cout << "Base(int)" << std::endl; }
	Base(float b) { std::cout << "Base(float)" << std::endl; }
	~Base()    { std::cout << "~Base()" << std::endl; }
};
class Derived : public Base
{
public:						
	Derived()		{ std::cout << "Derived()" << std::endl; }
	Derived(int a):Base((float)a)	{ std::cout << "Derived(int)" << std::endl; }
	~Derived()		{ std::cout << "~Derived()" << std::endl; }
};
int main()
{
	Derived d1;
	std::cout << "=====\n";
	Derived d2(5);
	std::cout << "=====\n";
}
