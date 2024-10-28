// 15page ~ 
#include <iostream>
#include <vector>


/*
	1. Design Pattern �̶�?
		=> 1994�� �߰��� å�� ������.
		=> 4���� ���ڰ� "��ÿ� �����ϴ� �ڵ� ��Ÿ��"�� "�̸��� �ο�" �� ��
		=> �� ��ÿ� �� 23���� ������. --> GoF's Design Pattern �̶�� ��.
		=> "Gangs Of Four" : 4���� ����.

	2. prototype pattern : ��ü�� ���纻�� ����� ���� clone() �����Լ��� ����� ���.
						   ����� �� ������ "����ϳ�"
						   �ᱹ �̹� �ִ� Ʋ�� ����ؼ� ���纻�� ����� ������ prototype pattern��.

	3. Refactoring���� ���Ǵ� ����Դϴ�. �ǹ̸� ������ ������.
		"replace conditional with polymorphism"
		"����� �ڵ忡 ___�� �ִٸ� ___�� ������ ����."
		"����� �ڵ忡 ���(if, switch) �� �ִٸ� ������(�����Լ�) �� ������ ����."
		--> ��, if, switch ����ϰ� �Ǹ� OCP ������Ű�� ��ƴٴ� �̾߱���.

		Refactoring : ������ code�� ���� ����� �� refactoring��.
*/


class Shape {
	int color;
public:
	virtual void draw() { std::cout << "draw Shape\n"; }
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	// �ڽ��� ���纻�� ����� �����Լ��� �׻� �����ϰ� ����.
	virtual Shape* clone() {
		Shape* p = new Shape;		// ���ο� ������ �����,
		p->color = this->color;		// �ڽ��� ��� ����� ����
		return p;					// �� �۾��� ���� �����ڷ� �۾��� �ص� ��.
	}
};

class Rect : public Shape {
public:
	void draw() override { std::cout << "draw rect\n"; }
	Shape* clone() override { return new Rect(*this); }
};

class Circle : public Shape {
public:
	void draw() override { std::cout << "draw circle\n"; }
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

			// �������� OCP�� �����ϴ� ���� ���� �ڵ���!!
			// ==> �������� �ᱹ "�����ռ�" �̴�.
			v.push_back(v[k]->clone());		// ������. k��° ������ ���� �� �ʿ� ����.
			// ���ο� ������ �߰��Ǿ �� �ڵ�� ������� �ʴ´�. (OCP)
			// don't ask. do it.
		}
	}
}


