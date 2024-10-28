#include <iostream>
#include <vector>
#include <map>
#include "Helper.h"

class Shape
{
public:
	virtual void draw() = 0;
	virtual Shape* clone() = 0;
	virtual ~Shape() {}
};

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	Shape* clone() override { return new Rect(*this); }
	static Shape* create() { return new Rect; }
};


class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	Shape* clone() override { return new Circle(*this); }
	static Shape* create() { return new Circle; }
};

class ShapeFactory
{
	MAKE_SINGLETON(ShapeFactory)

	std::map<int, Shape*> prototype_map;
public:
	void register_shape(int key, Shape* c)
	{
		prototype_map[key] = c;
	}

	Shape* create(int type)
	{
		Shape* p = nullptr;

		auto it = prototype_map.find(type);

		if (it != prototype_map.end())
		{
			p = it->second->clone();
		}
		return p;
	}
};




int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();


	// �Ʒ��ڵ�� ���忡 "�����Լ��� �Լ�������"�� ����ϴ� �ڵ� �Դϴ�.
	// => �ᱹ �ǵ��� "���忡 Ŭ����" �� ����ϰڴٴ� ��
//	factory.register_shape(1, &Rect::create);
//	factory.register_shape(2, &Circle::create);

	// ���忡 "Ŭ����" �� �ƴ� "���ֻ���ϴ� ��ü" �� ����� ���ô�.
	Rect* redRect = new Rect; // ������, �β�5, ũ��10�� �����Ѽ����� ����
	Rect* blueRect = new Rect;

	Circle* redCircle = new Circle;

	factory.register_shape(1, redRect);
	factory.register_shape(2, blueRect);
	factory.register_shape(3, redCircle);




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
