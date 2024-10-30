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

// 다른 곳에서 shapefactory 사용해야 해서 shapefactory 위치 변경.
// c++에서는 class 아래쪽에 있는 녀석들은 위쪽에 있는 class 사용을 할 수가 없음.
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

// 공장에 도형을 자동등록하는 class
//		=> 생성자만 사용
class AutoRegister {
public:
	AutoRegister(int key, Shape* (*f)()) {
		ShapeFactory::get_instance().register_shape(key, f);
	}
};

// 전역 변수의 생성자가 언제 호출되는지 생각해 보자.
//AutoRegister ar(1, &Rect::create);

class Rect : public Shape
{
public:
	void draw() override { std::cout << "draw Rect" << std::endl; }
	static Shape* create() { return new Rect; }

	/*
		static 멤버 데이터의 특징을 생각해 보면
			=> 객체를 한개도 만들지 않아도 메모리에 생성됨.
			=> 프로그램 처음 실행 시 생성. (결국 전역변수 이니까)
			=> 즉, main 함수 이전에 ar 생성자가 호출됨.
	*/
	inline static AutoRegister ar{ 1, &Rect::create };
};

class Circle : public Shape
{
public:
	void draw() override { std::cout << "draw Circle" << std::endl; }
	static Shape* create() { return new Circle; }

	// C++17 inline static 으로 하면 외부 선언 없어도 됨.
	// 단, 클래스 안에서는 () 가 아닌 {} 초기화 사용
	inline static AutoRegister ar{ 2, &Circle::create };
};

/*
	아래의 내용 생각해 보자
							// Rect::ar 의 생성자 호출 (결국 클래스에 대해서 한번 호출). 즉, class 전체에 대해서 한번만 호출됨.
	Rect* r1 = new Rect;	// Rect 생성자 호출
	Rect* r2 = new Rect;
	Rect* r3 = new Rect;
							// 생성자는 객체당 한번씩 호출


	C# 에는 static 생성자라는 문법이 있음.
	Class Car {
		public Car() {}		// instance 생성자
		static Car() {}		// static 생성자, 접근지정자 표기 안함
	};

	Car c1 = new Car();	// static 생성자 호출
						// instance 생성자 호출
	Car c2 = new Car();	// instance 생성자 호출
	
*/

int main()
{
	std::vector<Shape*> v;

	ShapeFactory& factory = ShapeFactory::get_instance();

	// 이미 각 도형의 static 멤버인 ar의 생성자에서 공장에 등록 완료.
	//factory.register_shape(1, &Rect::create);
	//factory.register_shape(2, &Circle::create);

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




