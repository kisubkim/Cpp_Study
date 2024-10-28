﻿#include <iostream>
#include <vector>
#include <map>
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

	// 자신을 만드는 static 멤버 함수는 아주 유용하게 활용됩니다.
	static Shape* create() { return new Rect; }
};

// Rect 객체를 만드는 2가지 방법
// 1. Rect* r1 = new Rect;			// 클래스 이름을 알아야 합니다.
// 2. Rect* r2 = Rect::create();	// 클래스 이름을 몰라도 함수주소만
//									// 알면 객체 생성 가능합니다.

// #1. C++ 에서는 "클래스 이름" 을 자료구조에 보관할수 없습니다.
// v.push_back("Rect"); // 클래스 이름이 아닌 문자열 보관한것. 문자열로는 객체생성안됨
// v.push_back(Rect);   // 이렇게 하고 싶지만, 안됨.

// #2. 하지만 함수 주소는 자료구조에 보관됩니다.
// v.push_back(&Rect::create);












class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }
};


class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

		using CREATOR = Shape * (*)();

	std::map<int, CREATOR> create_map;
public:
	void register_shape(int key, CREATOR c)
	{
		create_map[key] = c;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;

		auto it = create_map.find(type);

		if (it != create_map.end())
		{
			p = it->second(); // 현재 map 의 value 는 생성함수!!
			// 따라서, () 로 호출해서 도형생성
		}
		return p;
	}
};




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 공장을 사용하기 전에. 제품을 먼저 등록해야 합니다.
	// => 도형 번호와 생성함수 를 등록
	factory.register_shape(1, &Rect::create);
	factory.register_shape(2, &Circle::create);


	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd >= 1 && cmd <= 7)
		{
			Shape* s = factory.create(cmd);

			if (s != nullptr)
				v.push_back(s);
		}
		else if (cmd == 9)
		{
			for (int i = 0; i < v.size(); i++)
			{
				v[i]->draw();
			}
		}
	}
}


