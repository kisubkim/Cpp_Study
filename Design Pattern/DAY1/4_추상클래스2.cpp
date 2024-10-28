//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera
{
public:
	void take() { std::cout << "Take HD Picture" << std::endl; }
};

class People
{
public:	
	void use_camera(Camera* p) { p->take(); }
	void use_camera(HDCamera* p) { p->take(); }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);
}



/*
	OCP : Open Close Principle
	미래의 기능 확장에는 열려 있고 (Open, 새로운 클래스(모듈)가 추가되어도)
	기존의 코드 수정에는 닫혀 있어야 (Close, 기존 코드는 수정되지 않도록)
	한다는 이론 (Principle)

	Open Close Principle : 개발 폐쇄의 법칙

	OOP SW Design 5대 원칙 (SOLID)
	1. SRP
	2. OCP
	3. LSP
	4. ISP
	5. DIP

    위의 예제는 OCP 위반임.
	 => HDCamera 추가 시 기존 클래스 People 이 수정되었음.


	 이미 HW 진영에서는 OCP 로 만들고 있음.
	 일반 PC, USB 등등 모두 표준 프로토콜이 있음.

	 SW 에서 이 HW 진영에서 하는 USB 프로토콜 같은 것들이 Interface 임.
*/




