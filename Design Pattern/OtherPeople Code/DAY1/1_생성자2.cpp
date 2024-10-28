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
	// 아래 코드가 왜 에러인지 생각해 보세요 -> base 클래스의 기본생성자가 없습니다.
	                              //      컴파일러가 멋대로 바꾼 코드.        
	//Derived() { }                 //  ==> Derived():Base() {}         
	//Derived(int a) { }            //  --> Derived(int a):Base() {}
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{

}
