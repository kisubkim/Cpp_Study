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
	// �Ʒ� �ڵ尡 �� �������� ������ ������ -> base Ŭ������ �⺻�����ڰ� �����ϴ�.
	                              //      �����Ϸ��� �ڴ�� �ٲ� �ڵ�.        
	//Derived() { }                 //  ==> Derived():Base() {}         
	//Derived(int a) { }            //  --> Derived(int a):Base() {}
	Derived()      : Base(0) {}
	Derived(int a) : Base(a) {}
};
int main()
{

}
