// 1_추상클래스1.cpp - 10page

// abstract class : pure virtual function이 하나 이상있는 class
// 특징 : 객체(instance)를 만들 수 없음.
//		  그래도 pointer는 선언 및 활용 가능함.
// 의도 : 약속된 함수를 반드시 만들라고 지시 하는 것.

class Shape
{
public:
	virtual void draw() = 0;		// 순수 가상함수 (pure virtual function) : 구현이 없고 "= 0" 으로 표기
							 
};
class Rect : public Shape
{
	// draw()의 구현을 제공하지 않으면 Rect도 추상(abstract)
	// draw()의 구현을 제공하면 Rect는 추상이 아님. (구체, concrete)
public:
	void draw() override {}	// 구현이 있다 --> abstract가 아님.
};
int main()
{
	Shape  s;		// Error 
	Shape* p;		// ok
	Rect  r;
}
