// 15page ~ 
#include <iostream>
#include <vector>
#include <cassert>

class NotImplemented {}; 
class Shape {
	int color;
public:
	virtual ~Shape() {};
	void set_color(int c) { color = c; };

	virtual void draw_imp() = 0;
	void draw() {                          // template method pattern.
		std::cout << "Mutex Lock\n";
		draw_imp();
		std::cout << "Unlock Mutex\n";
	}

	virtual Shape* clone() {
		throw NotImplemented();
	}
	virtual double get_area() { return -1; };
};

struct Rect : public Shape {
	int x, y;
	Rect(int x, int y) : x(x), y(y) {};
	void draw_imp() override
	{
		std::cout << "draw Rect\n"; 
	}

	Shape* clone() override { return new Rect(*this); } // 복사생성자
	double get_area() override { return x * y; }
};

struct Circle : public Shape {
	int r;
	void draw_imp() override { std::cout << "draw Circle\n"; }
	Shape* clone() override { return new Circle(*this); } // 복사생성자
	double get_area() override { return r * r * 3.14; };
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		if (cmd == 1) v.push_back(new Rect(1, 2));
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
			try {
				v.push_back(v[k]->clone());
			}
			catch (NotImplemented& e) {
				assert(false);
			}
		}
	}
}