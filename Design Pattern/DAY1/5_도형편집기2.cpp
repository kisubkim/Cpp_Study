// 15page ~ 
#include <iostream>
#include <vector>

/*
* 파워포인트 같은 SW를 만든다고 생각을 해보자.
*
*	1. 포든 도형을 타입화 하는 것이 편리함.
*	2. 모든 도형은 공통의 특징(color등)이 있음.
*		기반 클래스로 제공
*		기반 클래스가 있으면 모든 도형을 하나의 컨테이너에 보관할 수 있음
*/

class Shape {
	int color;
public:
	virtual void draw() = 0;
	virtual ~Shape() {}
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
			// Rect rc;		// 이렇게 만들면 {} 벗어나면 바로 파괴됨. 동적 할당 필요함.
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

// 흠...해결한거 같은데....

