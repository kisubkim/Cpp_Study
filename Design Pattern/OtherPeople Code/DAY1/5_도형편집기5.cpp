// 15page ~ 
#include <iostream>
#include <vector>
#include <cassert>

class NotImplemented {}; // empty class 로 만들어도 최선임. throw만 해주면 클래스 이름만 갖고도 알수가있다.

class Shape {
	int color;
public:
	virtual ~Shape() {};
	void set_color(int c) { color = c; };

	virtual void draw() = 0;

	// override 하지 않았는데 호출하면 예외발생
	// 호출안하면 잘 실행된다.
	virtual Shape* clone() {
		throw NotImplemented();
	}
	virtual double get_area() { return -1; };
};

struct Rect : public Shape {
	int x, y;
	Rect(int x, int y) : x(x), y(y) {};
	void draw() override { std::cout << "draw Rect\n"; }
	Shape* clone() override { return new Rect(*this); } // 복사생성자
	double get_area() override { return x * y; }
};

struct Circle : public Shape {
	int r;
	void draw() override { std::cout << "draw Circle\n"; }
	Shape* clone() override { return new Circle(*this); } // 복사생성자
	double get_area() override { return r*r*3.14 };
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect(1,2));
		else if (cmd == 2) v.push_back(new Circle(3));
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
			try {
				v.push_back(v[k]->clone());
			}
			catch (NotImplemented& e) {
				assert(false);
			}
		}
	}
}