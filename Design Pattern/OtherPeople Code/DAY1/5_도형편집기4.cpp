// 15page ~ 
#include <iostream>
#include <vector>

// #1. 리팩토링에서 사용되는 유우명한 용어
// replace conditional with polymorphism

// #2 디자인 패턴이란
// 1995년에 발간된 책의 제목
// GOF's Design Pattern - gangs of four - 4명의 강도 
// 이미 존재하던 기법을 훔쳐서 이름만 붙인 것입니다

// #3 Prototype Pattern
// 객체의 복사본을 만들 때 사용하는 패런
// clone 가상함수


// # command Pattern
// 현재 프로그램에 undo/redo를 넣을 수 있읍니다


class Shape {
	int color;
public:
	virtual ~Shape() {};
	virtual void draw() {
		std::cout << "draw shape\n";
	};
	void set_color(int c) { color = c; };
	virtual int get_area() { return 0; };

	virtual Shape* clone() = 0; // prototype 패턴
};

struct Rect : public Shape {

	void draw() {
		std::cout << "draw Rect\n";
	}

	Shape* clone() override { return new Rect(*this); }
};

struct Circle : public Shape {

	void draw() {
		std::cout << "draw Circle\n";
	}
	Shape* clone() override { return new Circle(*this); } // 복사생성자

};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect);
		else if (cmd == 2) v.push_back(new Circle);
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();
		}
		else if (cmd == 8)
		{
			std::cout << "몇 번쨰 만든 도형을 복제할깝쇼? : ";
			int k;
			std::cin >> k;
			// Shape* s = static_cast<Shape*>(v[k]); -> 포인터로 복사되니까 안됨.
			Shape* s = v[k]->clone();
			v.push_back(s);
		}
	}
}