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


//�簢���� ��� �׸����� �簢���� �˸� ��. �� template method�� �� ��︮�� ��
struct Rect : public Shape {
	int x, y;
	Rect(int x, int y) : x(x), y(y) {};
	void draw_imp() override
	{
		std::cout << "draw Rect\n";
	}

	Shape* clone() override { return new Rect(*this); } // ��������� 
	double get_area() override { return x * y; }
};

struct Circle : public Shape {
	int r;
	void draw_imp() override { std::cout << "draw Circle\n"; }
	Shape* clone() override { return new Circle(*this); } // ���������
	double get_area() override { return r * r * 3.14; };
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// ��ü�� ������ ��� �߻�ȭ �Ҽ�������? -> �߻� ���丮 �������� ¥�� �˴ϴ�.
		// undo / redo�� command Pattern���� ¥�� �˴ϴ�.

		if (cmd == 1) v.push_back(new Rect(1, 2));         // ocp �Ҹ���, ������ �Ҹ���.
		else if (cmd == 2) v.push_back(new Circle);       
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();             //ocp ���� ������ ����
		}
		else if (cmd == 8)
		{
			std::cout << "�� ���� ���� ������ �����ұ���? : ";
			int k;
			std::cin >> k;
			try {
				v.push_back(v[k]->clone()); //ocp���� ������ ����
			}
			catch (NotImplemented& e) {
				assert(false);
			}
		}
	}
}