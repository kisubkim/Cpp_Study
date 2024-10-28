#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	void cry() { std::cout << "Dog cry" << std::endl; }			// function override : base class func를 파생 class가 다시 만드는 것.
};
int main()
{
	Animal a;	a.cry();		// animal cry() 호출
	Dog d;		d.cry();		// dog cry() 호출
	Animal* p = &d; 

	p->cry();					// c++, c# : animal cry 호출 (기본 binding이 static binding)
								// Java, Python, swift, kotlin 등 대부분의 언어 : Dog cry 호출...헐...첨 알았네. (기본 binding이 dynamic binding)
								// 대부분의 객체지향 언어의 정책. 하지만 무조건 dynamic binding 사용해야함.
}

// p->cry() 를 어떤 함수와 연결할 것인가?
// => function binding 이라고 부름

/*
*	방식은 2가지가 있음.
* 
    1. static binding : 컴파일러가 컴파일 할 때 함수를 결정. 
						컴파일러는 p가 가리키는 곳에 어떤 객체가 있는지 알 수 없다. (변수니까...어케 변할지 어케 아누..)
						컴파일러가 아는 유일한 정보는 p자체의 type이 "Animal"이라는 것말 알고 있음.
						따라서, 컴파일러가 결정하는 "Animal::cry"를 호출하도록 기계어 코드 생성
						논리적이지는 않지만 빠름.

	2. dynamic binding : 컴파일 시간에는 "p가 가리키는 메모리를 조사" 하는 기계어 코드 생성
						실행 시, 메모리 조사하고 호출을 결정.
						p가 가리키는 곳에 Dog가 있었다면 "Dog::cry" 호출.
						논리적이지만 약간 느림.

*/

