// Decorator - 65 page
#include <iostream>

/*

*/
struct IDraw {
	virtual void draw() = 0;
	virtual ~IDraw() {}
};


class PhotoSticker : public IDraw
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() override { std::cout << "draw Photo\n"; }
};

// 기능추가 클래스(Decorator)들은 공통의 특징이 있을 수 있음
// 기반 클래스로 제공.
class Decorator : public IDraw {
	int x = 0;
	int y = 0;		// 기능(그림)을 추가할 위치
	IDraw* origin;		// 기능을 추가할 객체 포인터.
public:
	Decorator(IDraw* d) : origin(d) {}
	~Decorator() {}

	void draw() override { origin->draw(); }

};

class Emoticon : public Decorator {
public:
	Emoticon(IDraw* ps) : Decorator(ps) {}
	void draw() override {
		std::cout << "@@@@@@@@@@@@@@" << std::endl;
		Decorator::draw();
		std::cout << "@@@@@@@@@@@@@@" << std::endl;
	}
};

class Frame : public Decorator {
public:
	Frame(IDraw* ps) : Decorator(ps) {}
	void draw() override {
		std::cout << "##############" << std::endl;
		Decorator::draw();
		std::cout << "##############" << std::endl;
	}
};


int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();

	Emoticon e(&ps);
	e.draw();

	Frame f(&e);
	f.draw();

	ps.draw();

}
