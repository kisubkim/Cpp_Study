// 15page ~ 
#include <iostream>
#include <vector>

// 최종 ver
// code 정리 + 생각해 볼 문제

class unsupported_operation {};

class Shape {
	int color = 0;

protected:
	Shape() {}

public:
	void draw() {
		std::cout << "lock mutex\n";
		draw_imp();
		std::cout << "unlock mutex\n";
	}

	void set_color(int c) { color = c; }
	virtual ~Shape() {}

protected:
	virtual void draw_imp() = 0;

public:
	virtual Shape* clone() { throw unsupported_operation(); }

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

		// 아래 부분은 새로운 부분이 추가되면 수정되어야 하는 부분임.
		// 생각해 볼 문제
		// 1. 객체의 생성을 OCP를 만족하게 할 수 없을까? (Triangle을 추가해도 아래 code가 변경되지 않도록)
		//		=> Factory Pattern을 사용해서 처리 진행

		// 2. Undo / Redo 기능을 추가하려면 어떻게 해야 할까?
		//		=> Command Pattern을 배우면 되.
		//		=> Undo / Redo 할 때 사용하는 Pattern. (목요일)
		if (cmd == 1) {
			v.push_back(new Rect);
		}
		else if (cmd == 2) {
			v.push_back(new Circle);
		}
		else if (cmd == 9) {
			for (auto e : v) {
				e->draw();		// 다형성, OCP 만족
			}
		}
		else if (cmd == 8) {
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			v.push_back(v[k]->clone());		// 다형성, OCP 만족
		}
	}
}


