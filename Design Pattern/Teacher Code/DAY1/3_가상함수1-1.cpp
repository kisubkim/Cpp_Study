#include <iostream>

class Animal
{
public:
	// non-virtual : staic binding 해달라는 것
	//				컴파일 시간에 호출 결정. (포인터 타입으로 결정)
	void cry1() { std::cout << "Animal cry1" << std::endl; }

	// virtual : dynamic bidnign 해달라는 것
	//			실행시간에 메모리 조사 후 호출 결정(실제 객체 타입에 맞는 호출)
	virtual void cry2() { std::cout << "Animal cry2" << std::endl; }
};
class Dog : public Animal
{
public:
	void cry1() { std::cout << "Dog cry1" << std::endl; }
	virtual void cry2() { std::cout << "Dog cry2" << std::endl; }
};
int main()
{
	Dog d;
	Animal* p = &d;

	p->cry1();		// static binding. Animal cry1
	p->cry2();		// dynamic binding. Dog cry2
}

// assem code 를 보면 move 가 dynamic binding 할 때 여러번 호출됨. 이래서 성능이 좀 떨어짐.
