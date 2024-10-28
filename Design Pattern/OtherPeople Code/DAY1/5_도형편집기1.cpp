// 15page ~ 
#include <iostream>
#include <vector>

class Shape {
	int color;
public:
	virtual ~Shape() {};
	virtual void draw() = 0;
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
	Rect r;
	Circle c;

	std::vector<Shape*> v;
}