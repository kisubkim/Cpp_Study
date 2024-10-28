#include <iostream>

class Animal
{
public:
	//static binding c++ �⺻ ��å
	void cry1() { std::cout << "Animal cry1" << std::endl; }
	//dynamic binding ���� �� ���̳���
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog cry1" << std::endl; }

	// virtual ���. ���� �Ͱ� ��ư �������

	void cry2() { std::cout << "Dog cry2" << std::endl; }
};
int main()
{
	Dog d;
	
	Animal* p = &d;

	p->cry1();
	p->cry2();
}

// godbolt.org