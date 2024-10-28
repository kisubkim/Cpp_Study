// 15page ~ 
#include <iostream>
#include <vector>

class Shape {
	int color;
public:
	virtual ~Shape() {};
	virtual void draw() {
		std::cout << "draw shape\n";
	};
	void set_color(int c) { color = c; };
	virtual int get_area() = 0;
};

struct Rect : public Shape {

	void draw() {
		std::cout << "draw Rect\n";
	}
	int get_area() {
		return 2;
	}
};

struct Circle : public Shape {

	void draw() {
		std::cout << "draw Circle\n";
	}
	int get_area() {
		return 3;
	}
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
				s->draw(); //error
		}

	}
}