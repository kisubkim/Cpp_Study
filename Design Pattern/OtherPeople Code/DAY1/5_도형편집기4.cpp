// 15page ~ 
#include <iostream>
#include <vector>

// #1. �����丵���� ���Ǵ� ������� ���
// replace conditional with polymorphism

// #2 ������ �����̶�
// 1995�⿡ �߰��� å�� ����
// GOF's Design Pattern - gangs of four - 4���� ���� 
// �̹� �����ϴ� ����� ���ļ� �̸��� ���� ���Դϴ�

// #3 Prototype Pattern
// ��ü�� ���纻�� ���� �� ����ϴ� �з�
// clone �����Լ�


// # command Pattern
// ���� ���α׷��� undo/redo�� ���� �� �����ϴ�


class Shape {
	int color;
public:
	virtual ~Shape() {};
	virtual void draw() {
		std::cout << "draw shape\n";
	};
	void set_color(int c) { color = c; };
	virtual int get_area() { return 0; };

	virtual Shape* clone() = 0; // prototype ����
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
	Shape* clone() override { return new Circle(*this); } // ���������

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
			std::cout << "�� ���� ���� ������ �����ұ���? : ";
			int k;
			std::cin >> k;
			// Shape* s = static_cast<Shape*>(v[k]); -> �����ͷ� ����Ǵϱ� �ȵ�.
			Shape* s = v[k]->clone();
			v.push_back(s);
		}
	}
}