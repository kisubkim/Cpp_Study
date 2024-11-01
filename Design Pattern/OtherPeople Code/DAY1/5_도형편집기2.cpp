// 15page ~ 
#include <iostream>
#include <vector>

class Shape {
	int color;
public:
	virtual ~Shape() {};
};

struct Rect : public Shape {
	void draw() override {
		std::cout << "draw Rect\n";
	}
};

struct Circle : public Shape {
	void draw() override {
		std::cout << "draw Circle\n";
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