// 15page ~ 
#include <iostream>
#include <vector>

class Shape {
	int color;
public:
	virtual ~Shape() {}
};

class Rect : public Shape {
	// int x, y, w, h 와 생성자 등은 생략
public:
	void draw() { std::cout << "draw rect\n"; }
};

class Circle : public Shape {
	// int x, y, w, h 와 생성자 등은 생략
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
				// 해결책 접근 #1 : Shape* 타입인 e를 타입조사 후 casting 해서 사용.
				//e->draw();
				if (dynamic_cast<Rect*>(e) != nullptr) {
					static_cast<Rect*>(e)->draw();
				}
				else if (dynamic_cast<Circle*>(e) != nullptr) {
					static_cast<Circle*>(e)->draw();
				}
				
				// 위 코드는 새로운 도형이 추가되었을 때 (거의 성능저하는 없는데, 이는 static_cast 관련 내용임)
				// => 한줄이 추가되어야 함. (if문)
				// => OCP를 만족하지 않는 좋지 않은 코드임.
			}
		}
	}
}


