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

class ShapeFactory {
	MAKE_SINGLETON(ShapeFactory)
		using CREATOR = Shape * (*)();
	inline static std::map<int, CREATOR> create_map;
public:
	void register_shape(int key, CREATOR c) {
		create_map[key] = c;
	}

	Shape* create(int key) {
		Shape* p = nullptr;

		auto it = create_map.find(key);
		if (it != create_map.end()) {
			p = it->second();
		}
		return p;
	}
};

class AutoRegister {
public:
	AutoRegister(int key, Shape* (*f)()) {
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

#define REGISTER(key, classname)									\
	static Shape* create() { return new classname; }				\
	inline static AutoRegister ar{ key, &classname::create };

class Rect : public Shape {
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	REGISTER(1, Rect)
};

class Circle : public Shape {
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	REGISTER(2, Circle)
};

class Triangle : public Shape {
public:
	void draw() override { std::cout << "draw Triangle" << std::endl; }
	REGISTER(3, Triangle)
};



int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// factory.show_registered_product() 로 현재 등록된 것들 다 보여주게 하거나 하는 식으로도 할 수 있음.

	while (1) {
		int cmd;
		std::cin >> cmd;

		if (cmd > 0 && cmd < 8) {
			Shape* s = factory.create(cmd);

			if (s != nullptr) {
				v.push_back(s);
			}
		}
		else if (cmd == 9) {
			for (int i = 0; i < v.size(); i++) {
				v[i]->draw();
			}
		}
	}
}




