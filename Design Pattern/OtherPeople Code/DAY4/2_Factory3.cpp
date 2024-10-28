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


// ���忡 ��ǰ�� ����ϴ� ����� �����ϴ� Ŭ����
class AutoRegister
{
public:
	AutoRegister(int key, Shape* (*f)())
	{
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// �������� �����ڰ� ȣ��Ǵ� ������ ������ ������
// => main �Լ� ����Ǳ� ���� ȣ��. 
// AutoRegister ar(1, &Rect::create);






class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	static Shape* create() { return new Rect; }

	// static ��� ����Ÿ�� Ư¡�� �����غ�����
	// => ��� ��ü�� ����
	// => Rect ��ü�� ��� ���α׷� �����Ҷ� �����˴ϴ�.(������ ȣ��)
	//    ���������� ����
	static AutoRegister ar;
};
AutoRegister Rect::ar(1, &Rect::create);

//				// Rect::ar ������ ȣ��
// new Rect;	// ������ ȣ��
// new Rect;	// ������ ȣ��
// new Rect;	// ������ ȣ��
//				��, �����ڴ� ��ü�� �ѹ� ȣ��.
//				������, Rect::ar �� Rect Ŭ������ ���ؼ� �ѹ� ȣ��
//				=> Ŭ���� ��ü�� �ʱ�ȭ�� ���� Ŭ���� ������
/*
// C#���� static ������ ������ �ֽ��ϴ�.
class Car
{
	public Car() {} // instance ������
	static Car() {} // static ������, public ǥ�� ����.
					// ���� �̾ȿ����� static ��� ����Ÿ�� �ʱ�ȭ
};
Car c1 = new Car(); // 1. static ������ ȣ��
					// 2. instance ������ ȣ��

Car c1 = new Car();	// instance ������ ȣ��
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
