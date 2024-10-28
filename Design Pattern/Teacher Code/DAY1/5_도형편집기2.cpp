// 15page ~ 
#include <iostream>
#include <vector>

/*
* �Ŀ�����Ʈ ���� SW�� ����ٰ� ������ �غ���.
*
*	1. ���� ������ Ÿ��ȭ �ϴ� ���� ����.
*	2. ��� ������ ������ Ư¡(color��)�� ����.
*		��� Ŭ������ ����
*		��� Ŭ������ ������ ��� ������ �ϳ��� �����̳ʿ� ������ �� ����
*/

class Shape {
	int color;
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
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
			// Rect rc;		// �̷��� ����� {} ����� �ٷ� �ı���. ���� �Ҵ� �ʿ���.
			Rect* p = new Rect;
			v.push_back(p);
		}
		else if (cmd == 2) {
			v.push_back(new Circle);
		}
		else if (cmd == 9) {
			for (auto e : v) {
				e->draw();
			}
		}
	}
}

// ��...�ذ��Ѱ� ������....

