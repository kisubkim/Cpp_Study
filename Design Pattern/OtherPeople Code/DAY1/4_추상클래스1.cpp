// 1_추상클래스1.cpp - 10page
#include <iostream>
class Shape
{
public:
	virtual void draw() = 0;  // 순수 가상 함수 구현부가 없음. 하나라도 있으면 추상클래스라 칭한다. 반드시 오버라이드가필요한 놈이다
							 
};
class Rect : public Shape {
public :
	void draw() override {
		std::cout << "피카소 그림 그리기";
	}
};
int main()
{
	//Shape  s; 
	Shape* p; 
	Rect  r;
	r.draw();
}
