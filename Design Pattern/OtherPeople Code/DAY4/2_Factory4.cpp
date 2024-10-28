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


// ����, ���ο� ���� Ŭ������ ���鶧�� ���Ѿ� �ϴ� ��Ģ�� �ֽ��ϴ�.
// => �̷� ��Ģ�� �ڵ������ϴ� ��ũ�θ� �����ϸ� ���մϴ�.

#define REGISTER(key, classname)								\
	static Shape* create() { return new classname; }			\
	inline static AutoRegister ar{ key, &classname::create };

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }

	REGISTER(1, Rect)
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }

	REGISTER(2, Circle)
};

class Triangle : public Shape
{
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }

	REGISTER(3, Triangle)
};


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

