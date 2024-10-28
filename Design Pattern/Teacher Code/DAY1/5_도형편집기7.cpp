// 15page ~ 
#include <iostream>
#include <vector>

/*
	1. Template Method Pattern
		=> ������ ���� ��ü���� �帧�ӿ� ��� ���ؾ� �ϴ� ���� ã�Ƽ�
		   ������ �����Լ��� �и��ϴ� ����.
		=> �Ļ�Ŭ�������� ������ ��Ģ�� ���� ������
		   ���ؾ� �ϴ� �͸� ������ �� �ְ� �ϴ� ������ ����.
*/

class Shape {
	int color;
public:

	// ���뼺�� �������� �и�
	// => ������ �ʴ� code flow �ӿ� �ִ� ���ؾ� �ϴ� �ڵ�� �и��Ǿ�� �Ѵ�.
	// => ���ϴ� ���� ������ �����Լ��� �и��Ѵ�.
	// => ���ϴ� �κ��� �Ļ�Ŭ�������� �ٽ� �����ؾ� ������ protected�� �����ϴ°� ����.
protected:
	virtual void draw_imp() {
		std::cout << "draw Shape\n";
	}

public:
	// �Ʒ� �Լ��� ������ ���� ������ ��Ģ�̹Ƿ� override ���� �ʵ��� �Ѵ�. (virtual ����)
	// non-virtual
	// �Ʒ�ó�� ��ü���� Ʋ�� ���� �Լ��� ǥ���ϴ� Pattern�� Template Method��.
	void draw()
	{

		std::cout << "lock mutex\n";

		draw_imp();

		std::cout << "unlock mutex\n";

	}
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	virtual Shape* clone() {
		Shape* p = new Shape;
		p->color = this->color;
		return p;
	}
};

class Rect : public Shape {
public:
	void draw_imp() override { std::cout << "draw rect\n"; }
	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape {
public:
	void draw_imp() override { std::cout << "draw circle\n"; }
	Shape* clone() override { return new Circle(*this); }
};


int main()
{
	std::vector<Shape*> v;
	while (1) {
		int cmd;
		std::cin >> cmd;
		if (cmd == 1) {
			v.push_back(new Rect);
		}
		else if (cmd == 2) {
			v.push_back(new Circle);
		}
		else if (cmd == 9) {
			for (auto e : v) {
				e->draw();
			}
		}
		else if (cmd == 8) {
			std::cout << "���° ������ ���� �ұ�� >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());	
		}
	}
}


