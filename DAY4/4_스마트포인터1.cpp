#include <iostream>

//^ 개념 : 임의의 객체가 다른 타입의 포인터 역활을 하는 것
//^ 원리 : -> 와 * 여산자를 재정의해서 포인터 처러 보이게 하는 것
//^ 장점 : 진짜 포인터가 아닌 객체
//^		생성/복사/대입/파괴의 순간에 추가적인 작업 가능
//^		대표적 활용이 소멸자에서 자원을 delete 하는 기능

class Car
{
public:
	void Go() { std::cout << "Go" << std::endl; }
	~Car()    { std::cout << "~Car" << std::endl; }
};

class Ptr
{
	Car* obj;
public:
	Ptr(Car* p = 0) : obj(p) {}
	~Ptr() { delete obj; }

	Car* operator->() { return obj; }
	Car& operator*() { return *obj; }
};

int main()
{
	// 아래 p 는 object 임.
	Ptr p = new Car; 	// Ptr p(new Car); ---> 이것과 동일.

	// 그런데 사용하는 건 pointer 처럼 사용되네.
	// 요런 개념이 smart pointer 이다.
	p->Go(); 		//^ Ptr p 가 Car* 처럼 사용됨.
					//^ (p.operator) Go() 의 모양이지만
					//^ (p.operator->())->Go() 의 형태로 해석.
	(*p).Go();
}


