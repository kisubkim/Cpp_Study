// 15page ~ 
#include <iostream>
#include <vector>

/*
	1. 모든 파생 클래스의 공통의 특징은 반드시 기반 클래스에도 있어야함.
	   문법적인 규칙이 아닌 "디자인 규칙"!! (중요)

	   그래야 기반 클래스 포인터로 해당 기능을 사용할 수 있음.

	2. 기반 클래스가 가진 함수중에서 파생클래스가 override 하는 것은 반드시 virtual 이어야 한다.
	   (문법적인 규칙이 아닌 "디자인 규칙")
*/

class Shape {
	int color;
public:
	virtual void draw() { std::cout << "draw Shape\n"; }
	virtual ~Shape() {}

	// 아래 함수는 virtual ? or non-virtual?
	// 솔직히 이건 override할 이유가 별로 없음. 
	// virtual 로 하면 일단 좀 느림..그래서 꼭 할 필요는 없음.
	void set_color(int c) { color = c; }

	// 면적은 구하는 방법이 도형마다 다름으로 virtual로 하는게 좋음.
	virtual int get_area() { return 0; }
};

class Rect : public Shape {
	// int x, y, w, h 와 생성자 등은 생략
public:
	void draw() override { std::cout << "draw rect\n"; }
};

class Circle : public Shape {
	// int x, y, w, h 와 생성자 등은 생략
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
				e->draw();			// 다형성 (Polymorphism) : 동일한 표현식이 상황(실제객체의 종류)에 따라 다르게 동작하는 것.
				/*
					OOP 3대 특징 : 캡슐화, 상속, 다형성
					1. 다형성의 장점
						=> 위 예제에 새로운 도형 (ex> Triangle)이 추가되어도 "e->draw()"는 변하지 않음.
						=> OCP 만족.
				*/
			}
		}
	}
}


