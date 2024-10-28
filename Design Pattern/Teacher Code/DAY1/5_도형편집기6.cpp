// 15page ~ 
#include <iostream>
#include <vector>


/*
	1. Design Pattern 이란?
		=> 1994년 발간된 책의 제목임.
		=> 4명의 저자가 "당시에 유행하던 코딩 스타일"에 "이름을 부여" 한 것
		=> 그 당시에 총 23개를 정의함. --> GoF's Design Pattern 이라고 함.
		=> "Gangs Of Four" : 4명의 갱단.

	2. prototype pattern : 객체의 복사본을 만들기 위해 clone() 가상함수를 만드는 기술.
						   제대로 된 예제는 "목요일날"
						   결국 이미 있는 틀을 사용해서 복사본을 만드는 패턴이 prototype pattern임.

	3. Refactoring에서 사용되는 용어입니다. 의미를 이해해 보세요.
		"replace conditional with polymorphism"
		"당신의 코드에 ___가 있다면 ___로 변경해 봐라."
		"당신의 코드에 제어문(if, switch) 가 있다면 다형성(가상함수) 로 변경해 봐라."
		--> 즉, if, switch 사용하게 되면 OCP 만족시키기 어렵다는 이야기임.

		Refactoring : 안좋은 code를 좋게 만드는 게 refactoring임.
*/


class Shape {
	int color;
public:
	virtual void draw() { std::cout << "draw Shape\n"; }
	virtual ~Shape() {}

	void set_color(int c) { color = c; }

	virtual int get_area() { return 0; }

	// 자신의 복사본을 만드는 가상함수는 항상 유용하게 사용됨.
	virtual Shape* clone() {
		Shape* p = new Shape;		// 새로운 도형을 만들고,
		p->color = this->color;		// 자신의 모든 멤버를 복사
		return p;					// 위 작업을 복사 생성자로 작업을 해도 됨.
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
			std::cout << "몇번째 도형을 복제 할까요 >> ";

			int k;
			std::cin >> k;

			// 다형성은 OCP를 만족하는 아주 좋은 코드임!!
			// ==> 다형성은 결국 "가상합수" 이다.
			v.push_back(v[k]->clone());		// 다형성. k번째 도형이 뭔지 알 필요 없음.
			// 새로운 도형이 추가되어도 이 코드는 변경되지 않는다. (OCP)
			// don't ask. do it.
		}
	}
}


