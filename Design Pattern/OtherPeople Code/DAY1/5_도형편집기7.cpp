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


//사각형을 어떻게 그릴지는 사각형만 알면 됨. 즉 template method가 잘 어울리는 것
struct Rect : public Shape {
	int x, y;
	Rect(int x, int y) : x(x), y(y) {};
	void draw_imp() override
	{
		std::cout << "draw Rect\n";
	}

	Shape* clone() override { return new Rect(*this); } // 복사생성자 
	double get_area() override { return x * y; }
};

struct Circle : public Shape {
	int r;
	void draw_imp() override { std::cout << "draw Circle\n"; }
	Shape* clone() override { return new Circle(*this); } // 복사생성자
	double get_area() override { return r * r * 3.14; };
};

int main()
{
	std::vector<Shape*> v;

	while (1)
	{
		int cmd;
		std::cin >> cmd;

		// 객체의 생성은 어떻게 추상화 할수있을까? -> 추상 팩토리 패턴으로 짜면 됩니다.
		// undo / redo는 command Pattern으로 짜면 됩니다.

		if (cmd == 1) v.push_back(new Rect(1, 2));         // ocp 불만족, 다형성 불만족.
		else if (cmd == 2) v.push_back(new Circle);       
		else if (cmd == 9)
		{
			for (auto s : v)
				s->draw();             //ocp 만족 다형성 만족
		}
		else if (cmd == 8)
		{
			std::cout << "몇 번쨰 만든 도형을 복제할깝쇼? : ";
			int k;
			std::cin >> k;
			try {
				v.push_back(v[k]->clone()); //ocp만족 다형성 만족
			}
			catch (NotImplemented& e) {
				assert(false);
			}
		}
	}
}