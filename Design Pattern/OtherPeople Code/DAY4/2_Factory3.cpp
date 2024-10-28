#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
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
			p = it->second();
		}
		return p;
	}
};


// 공장에 제품을 등록하는 기능을 수행하는 클래스
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// 전역변수 생성자가 호출되는 시점을 생각해 보세요
// => main 함수 실행되기 전에 호출. 
// AutoRegister ar(1, &Rect::create);






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static 멤버 데이타의 특징을 생각해보세요
	// => 모든 객체가 공유
	// => Rect 객체가 없어도 프로그램 시작할때 생성됩니다.(생성자 호출)
	//    전역변수와 동일
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

//				// Rect::ar 생성자 호출
// new Rect;	// 생성자 호출
// new Rect;	// 생성자 호출
// new Rect;	// 생성자 호출
//				즉, 생성자는 객체당 한번 호출.
//				하지만, Rect::ar 은 Rect 클래스에 대해서 한번 호출
//				=> 클래스 자체의 초기화를 위한 클래스 생성자
/*
// C#에는 static 생성자 문법이 있습니다.
class Car
{
	public Car() {} // instance 생성자
	static Car() {} // static 생성자, public 표기 안함.
					// 보통 이안에서는 static 멤버 데이타의 초기화
};
Car c1 = new Car(); // 1. static 생성자 호출
					// 2. instance 생성자 호출

Car c1 = new Car();	// instance 생성자 호출
*/








class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	static Shape* create() { return new Circle; }

	static AutoRegister ar;
};
AutoRegister Circle::ar(2, &Circle::create);



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

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
