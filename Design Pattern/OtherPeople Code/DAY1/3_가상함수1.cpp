#include <iostream>

class Animal
{
public:
	void cry() { std::cout << "Animal cry" << std::endl; } 
};
class Dog : public Animal
{
public:
	void cry() { std::cout << "Dog cry" << std::endl; } 
};
int main()
{
	Animal a; a.cry();
	Dog d;    d.cry();
	Animal* p = &d; 

	//실제 객체는 dog, pinter 타입은 animal*

	p->cry();
	// c++, c# => animal,    java python 등등은 dogcry
}

/*
	p->cry()를 실제 어떠한 함수와 연결할 것인가?
	함수 바인딩 (function binding)

	1. static binding - compile 시간에 결정 - 컴파일러가 어떤 함수를 호출할 지 결정
	   컴파일러는 p가 가리키는 실제 객체의 종류를 알 수 없기 때문에, 무조건 상위 클래스를 부름 
	   여기서는 animal의 cry를 부르게 된다.

	논리적으로는 틀리지만, 빠르다
	C++과 C#의 기본 바인딩 정책
	
	
	2. dynamic binding - compile 시간에는 p가 가리키는 객체를 조사하는 코드를 생성하고
	                     runtime에 메모리를 조사해서 실제 객체 타입을 확인하여 호출을 결정하게 된다.
	
	논리적이지만, 실행시 조사를 하느라 느리다
	JAVA, Python, Swift, Kotlin 등 대부분의 객체지향 언어의 바인딩 방식
	C++/C#은 위와 같이 쓰려면 가상함수를 사용한다.

*/


