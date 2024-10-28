//1_추상클래스2.cpp
#include <iostream>


class Camera
{
public:	
	virtual void take() { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : Camera
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

//ocp 규칙 
//기능 확장에는 열려있고 코드 수정에는 닫혀있다
// 시험문제의 답은 OCP




