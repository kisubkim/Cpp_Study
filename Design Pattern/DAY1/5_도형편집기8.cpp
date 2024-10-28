// 15page ~ 
#include <iostream>
#include <vector>

// ���ܷ� ����ϱ� ���� Ÿ��.
class unsupported_operation {};

class Shape {
	int color;
public:
	void draw()
	{
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";
	}

	void set_color(int c) { color = c; }


	virtual ~Shape() {}


	// virtual function : �Ļ� Ŭ������ override ���� ������ �⺻ ���������Ѵٴ� �ǵ���.
	// pure virtual function : �Ļ� Ŭ������ "�ݵ�� �����"�� �����ϴ� ��.
protected:
	virtual void draw_imp() = 0;

public:
	// clone �� ��쵵 "������ ����" �� ���� ����.
	// 1. ���� �����Լ��� �ص� ����.
	//    => ���� �����Լ��� ��������, �Ļ� Ŭ������ ���Ѿ� �ϴ� ��Ģ�� ������.
	// 2. �Ʒ�ó�� �� ���� ����.
	//	  => �⺻ �������� ���� �߻�.
	//	  => C#, Python ���� �θ� ���Ǵ� ������ ���

	// 1. �Ļ� Ŭ�������� override ���� �ʰ�, ��뵵 ���� ������ ok
	// 2. �Ļ� Ŭ�������� override ���� �ʰ�, ����ߴٸ� ���� �߻�. runtime error
	// 3. �Ļ� Ŭ�������� override �ϰ� ����ϸ� ok.
	virtual Shape* clone() { throw unsupported_operation(); }

	// �Ʒ� ��쵵 
	// 1. ���� �����Լ��� ������ �ʰ�,
	// 2. ���� ������ ����� ����.
	// 3. �߸��� ������ ��ӵ� ���� �����ϴ�(C���)�� �θ� ���
	virtual int get_area() { return -1; }		// ������ 3���� ������ case
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


