#include <iostream>
#include <vector>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
};
class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
};

/*
	도형을 만드는 팩토리
		=> 공장에서만 도형을 만들기 때문에 나머지 주석은 나중에 update 할 것.
*/

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)
public:
	Shape* create(int type)
	{
		Shape* p = nullptr;
		if      (type == 1)	p = new Rect;
		else if (type == 2)	p = new Circle;
		return p;
	}
};


int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	while (1) {
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8) {		// 1 ~ 7을 도형의 번호로 예약
			Shape* s = factory.create(cmd);

			if (s != nullptr) {
				v.push_back(s);
			}
			// 이렇게 하면 이제 변하지 않음.
		} else if (cmd == 9) {
			for (int i = 0; i < v.size(); i++) {
				v[i]->draw();		// OCP 만족. 새로운 도형 추가되어도 변하지 않음.
			}
		}
	}
}




