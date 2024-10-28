// 15page ~ 
#include <iostream>
#include <vector>
#include <cassert>

class NotImplemented {}; // empty class �� ���� �ּ���. throw�� ���ָ� Ŭ���� �̸��� ���� �˼����ִ�.

class Shape {
	int color;
public:
	virtual ~Shape() {};
	void set_color(int c) { color = c; };

	virtual void draw() = 0;

	// override ���� �ʾҴµ� ȣ���ϸ� ���ܹ߻�
	// ȣ����ϸ� �� ����ȴ�.
	virtual Shape* clone() {
		throw NotImplemented();
	}
	virtual double get_area() { return -1; };
};

struct Rect : public Shape {
	int x, y;
	Rect(int x, int y) : x(x), y(y) {};
	void draw() override { std::cout << "draw Rect\n"; }
	Shape* clone() override { return new Rect(*this); } // ���������
	double get_area() override { return x * y; }
};

struct Circle : public Shape {
	int r;
	void draw() override { std::cout << "draw Circle\n"; }
	Shape* clone() override { return new Circle(*this); } // ���������
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
			std::cout << "�� ���� ���� ������ �����ұ���? : ";
			int k;
			std::cin >> k;
			// Shape* s = static_cast<Shape*>(v[k]); -> �����ͷ� ����Ǵϱ� �ȵ�.
			try {
				v.push_back(v[k]->clone());
			}
			catch (NotImplemented& e) {
				assert(false);
			}
		}
	}
}