#include <iostream>

class Base
{
public:
	
protected: 
	~Base() {
		std::cout << "~Base() �ڿ�����" << std::endl;
	}
};
class Derived : public Base
{
public:
	Derived() { std::cout << "Derived() �ڿ��Ҵ�" << std::endl; }
	~Derived() { std::cout << "~Derived() �ڿ�����" << std::endl; }
};
int main()
{

	//�׷��� �����Լ��� ���� ������, ���� �Լ� table�� ���� ������尡 �߻��ϰԵȴ�.

	//�� �ٸ� �ذ�å - protected �Ҹ���. -> �ܺο��� �׳� protected�� �Ҹ��ڸ� ������ �ع����� �ȴ�
	Base* p = new Derived; 
	//delete p;  // error

	delete static_cast<Derived*>(p);
	// �Ҹ��ڰ� ������ �ƴϹǷ� ����ڰ� �����ؼ� ����϶�� ���̴�.
}
