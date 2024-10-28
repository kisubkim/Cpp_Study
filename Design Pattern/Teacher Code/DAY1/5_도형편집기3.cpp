// 15page ~ 
#include <iostream>
#include <vector>

class Shape {
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape {
	// int x, y, w, h �� ������ ���� ����
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape {
	// int x, y, w, h �� ������ ���� ����
public:
	void draw() { std::cout << "draw circle\n"; }
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
				// �ذ�å ���� #1 : Shape* Ÿ���� e�� Ÿ������ �� casting �ؼ� ���.
				//e->draw();
				if (dynamic_cast<Rect*>(e) != nullptr) {
					static_cast<Rect*>(e)->draw();
				}
				else if (dynamic_cast<Circle*>(e) != nullptr) {
					static_cast<Circle*>(e)->draw();
				}
				
				// �� �ڵ�� ���ο� ������ �߰��Ǿ��� �� (���� �������ϴ� ���µ�, �̴� static_cast ���� ������)
				// => ������ �߰��Ǿ�� ��. (if��)
				// => OCP�� �������� �ʴ� ���� ���� �ڵ���.
			}
		}
	}
}


