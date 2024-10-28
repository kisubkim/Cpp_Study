//1_추상클래스2.cpp
#include <iostream>


/*
* 아래 2개의 용어가 혼용되어 사용되곤 하는데 약간의 차이점이 있음.
*		Abstract Class : 지켜야 하는 규칙(pure virtual function) + 다른 멤버
*		Interface : 지켜야 하는 규칙 (pure virtual function)
*	
*/

// 여기서 Interface 실습을 해보자.
// 구체적인 Camera를 머저 만들지 말고 모든 카메라가 지켜야 하는 규칙을 먼저 설계한다.

/*
* 규칙
	1. "모든 카메라는 아래 클래스로 부터 파생" 이라고 표현하지 말고
	   "모든 카메라는 아래 인터페이스를 구현해야 한다" 라고 표현.
*/	


// c++ 에서 struct와 class의 차이는 오로지 public, private 정도만 있음.
// 그래서 접근 지정자 관련해서 적게 쓰려고 public이 많으면 struct로 사용을 하기도 함.
// class : 접근지정자 생략하면 private
// struct : 접근지정자 생략하면 public

// 옛날에 유행했던 습관
#define interface struct
// 요렇게 해놓고, 아래에서 class 대신에 class 사용.

class ICamera {
public :
	virtual void take() = 0;
	virtual ~ICamera() {}			// Interface도 결국 기반 클래스임.
									// 따라서 소멸자를 반드시 "virtual"로 생성해야함.
};

// 위의 class는 Interface라고 말 할 수 있고, 만약에 member variable이 있으면 abstract class 임.
// Java, C# : 별도의 키워드 (interface, class) 존재. --> 따라서 c++처럼 혼용해서 쓰면 error남
// C++ : 별도의 키워드 없이, 추상클래스 문법으로만 모두 만들게 됨.

/*
	강한결합 (Tightly Coupling)
		=> 하나의 클래스가 다른 클래스 사용 시 "클래스이름을 직접" 사용하는 것
		=> People::use_camera(Camera*) 와 같은 형태.
		=> 교체 불가능한 경직된 디자인.

	약한결합 (Loosely Coupling)
		=> 하나의 클래스가 다른 클래스 사용 시 "규칙을 담은 Interface 이름" 을 통해서 접근 하는 것
		=> People::use_camera(ICamera*) 와 같은 형태.
		=> 교체 가능한 유연한 디자인.
*/


// 실제 카메라가 없어도, 규칙이 있다.
// 사용하는 코드를 작성할 수도 있음.
// 규칙대로만 사용하면 됨.

class People {
public :
	void use_camera(ICamera* c) { c->take(); }		// abstract는 객체를 가질 수 없지만 pointer를 가질 수는 있음.
};

class Camera : public ICamera
{
public:
	void take() override { std::cout << "Take Picture" << std::endl; }
};

class HDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take HD Picture" << std::endl; }
};

class UHDCamera : public ICamera
{
public:
	void take() override { std::cout << "Take UHD Picture" << std::endl; }
};

int main()
{
	People p;
	Camera c;
	p.use_camera(&c);

	HDCamera hc;
	p.use_camera(&hc);

	UHDCamera uhc;
	p.use_camera(&uhc);
}





