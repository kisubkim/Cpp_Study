// Decorator - 65 page
#include <iostream>

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

/*
	 현재 목표는 현재 존재하는 객체에 추가하는 것.

*/

class Emoticon {
	PhotoSticker* origin;
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}
	void draw() {
		std::cout << "@@@@@@@@@@@@@@" << std::endl;
		origin->draw();
		std::cout << "@@@@@@@@@@@@@@" << std::endl;
	}
};

// 액자 그림 기능을 추가하는 클래스
class Frame {
	PhotoSticker* origin;
public:
	Frame(PhotoSticker* ps) : origin(ps) {}
	void draw() {
		std::cout << "##############" << std::endl;
		origin->draw();
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

	//Frame f(&ps);
	Frame f(&e);			// 기능의 중첩
							// 현재 code에서는 error, 해결은 다음 소스에서
	f.draw();
}
