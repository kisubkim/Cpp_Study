#include <iostream>

class Animal
{
public:
	//static binding c++ 기본 정책
	void cry1() { std::cout << "Animal cry1" << std::endl; }
	//dynamic binding 실행 시 따이나믹
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog cry1" << std::endl; }

	// virtual 없어도. 붙인 것과 가튼 결과나까

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