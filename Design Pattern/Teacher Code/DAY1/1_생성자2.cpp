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
	// �Ʒ� �ڵ尡 �� �������� ������ ������
	// ������ �Ƹ� Base�� Base() �� �����.

	/*Derived() { }*/
	// compiler�� �� code�� ���߿� Derived() : Base(), Derived(int a) : Base() �� ���� Error�� ��.
	//Derived(int a) { }

	// �ٽ�
	// 1. base class�� defualt constructor�� ������ �ݵ�� �Ļ� Ŭ���� �����ڿ��� 
	//    base class�� �ٸ� constructor�� ȣ���ؾ���.

	Derived() : Base(0) { }
	Derived(int a) : Base(0) { }
};
int main()
{

}
