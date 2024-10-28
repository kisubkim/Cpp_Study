// 15page ~ 
#include <iostream>
#include <vector>

/*
	1. ��� �Ļ� Ŭ������ ������ Ư¡�� �ݵ�� ��� Ŭ�������� �־����.
	   �������� ��Ģ�� �ƴ� "������ ��Ģ"!! (�߿�)

	   �׷��� ��� Ŭ���� �����ͷ� �ش� ����� ����� �� ����.

	2. ��� Ŭ������ ���� �Լ��߿��� �Ļ�Ŭ������ override �ϴ� ���� �ݵ�� virtual �̾�� �Ѵ�.
	   (�������� ��Ģ�� �ƴ� "������ ��Ģ")
*/

class Shape {
	int color;
public:
	virtual void draw() { std::cout << "draw Shape\n"; }
	virtual ~Shape() {}

	// �Ʒ� �Լ��� virtual ? or non-virtual?
	// ������ �̰� override�� ������ ���� ����. 
	// virtual �� �ϸ� �ϴ� �� ����..�׷��� �� �� �ʿ�� ����.
	void set_color(int c) { color = c; }

	// ������ ���ϴ� ����� �������� �ٸ����� virtual�� �ϴ°� ����.
	virtual int get_area() { return 0; }
};

class Rect : public Shape {
	// int x, y, w, h �� ������ ���� ����
public:
	void draw() override { std::cout << "draw rect\n"; }
};

class Circle : public Shape {
	// int x, y, w, h �� ������ ���� ����
public:
	void draw() override { std::cout << "draw circle\n"; }
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
				e->draw();			// ������ (Polymorphism) : ������ ǥ������ ��Ȳ(������ü�� ����)�� ���� �ٸ��� �����ϴ� ��.
				/*
					OOP 3�� Ư¡ : ĸ��ȭ, ���, ������
					1. �������� ����
						=> �� ������ ���ο� ���� (ex> Triangle)�� �߰��Ǿ "e->draw()"�� ������ ����.
						=> OCP ����.
				*/
			}
		}
	}
}


