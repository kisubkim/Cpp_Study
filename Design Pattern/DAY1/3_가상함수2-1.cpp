#include <iostream>

// 1. ��� Ŭ������ �Ҹ��ڴ� �⺻������ virtual �̾�� ��.
// 2. �׷���, virtual �Լ��� ������
//   ==> �����Լ� ���̺��� �޸𸮿� ���̰� ��. (�޸� ��뷮 ��)
//   ==> ȣ�� ��, �޸� ���綧���� �ణ�� �������ϰ� ����.
// 3. �Ʒ� ���� �ڵ尡 ���ٸ� �Ҹ��ڸ� virtual �� ���� �ʾƵ� ��.
// Base* p = new Derived;
// delete p;	//	<---- ��κ�
// 4. 3��ó�� ������� �� ������ �������� �غ���!!
//    ==> protected �Ҹ���.

// �ᱹ �̰� ���� Ŭ������ ���� ������� ���� ���� �̷��� ����ϸ� ����.
// abstract ����� �� �� ��Ģ�� �߿��� ����.

class Base
{
protected:
	~Base() {}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{
	Base* p = new Derived;	
	delete p;		// �� ���� ����Ҹ��ڰ� �ƴϹǷ� ~Base�� ȣ���ؾ� �ϴµ�..
					// protected�� �־ Error!

	delete static_cast<Derived*>(p);		// �� code�� OK. ��� ~Derived() ȣ��
}
