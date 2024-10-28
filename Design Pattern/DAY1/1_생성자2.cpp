#include <iostream>

class Base
{
public:
	Base(int a) {  }
	~Base() {  }
};

class Derived : public Base
{
public:
	// 아래 코드가 왜 에러인지 생각해 보세요
	// 이유는 아마 Base에 Base() 가 없어서임.

	/*Derived() { }*/
	// compiler가 이 code를 나중에 Derived() : Base(), Derived(int a) : Base() 로 만들어서 Error가 남.
	//Derived(int a) { }

	// 핵심
	// 1. base class에 defualt constructor가 없으면 반드시 파생 클래스 생성자에서 
	//    base class의 다른 constructor를 호출해야함.

	Derived() : Base(0) { }
	Derived(int a) : Base(0) { }
};
int main()
{

}
