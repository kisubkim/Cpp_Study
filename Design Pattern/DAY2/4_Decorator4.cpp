// Decorator - 65 page
#include <iostream>

/*
	클래스와 클래스에 "기능을 추가하는 클래스(Decorator)"
	는 공통의 기반 클래스가 있어야 "중첩된 기능추가"가 가능함.

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



class Emoticon : public IDraw {
	IDraw* origin;
public:
	Emoticon(IDraw* ps) : origin(ps) {}
	void draw() override {
		std::cout << "@@@@@@@@@@@@@@" << std::endl;
		origin->draw();
		std::cout << "@@@@@@@@@@@@@@" << std::endl;
	}
};

// 액자 그림 기능을 추가하는 클래스
class Frame : public IDraw {
	IDraw* origin;
public:
	Frame(IDraw* ps) : origin(ps) {}
	void draw() override {
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
	Frame f(&e);
	f.draw();		// 기능 추가된 것을 사용.

	ps.draw();		// 기능 추가 전의 객체도 사용가능.


	// 자주 나오는 질문
	// 아래처럼 fillter 개념으로 하면 안되나요??

	/*
	PhotoSticker ps;
	ps.take();

	ps.add_filter(new Emoticion);
	ps.add_filter(new Frame);

	ps.draw();		// 등록된 필터를 모두 출력하고 촬영된 사진 출력.
	// 이 모델은 "원본 그림만 출력" 하는 기능이 없음.
	// ==> 필터를 제거하고 그려야함.
	*/
}
