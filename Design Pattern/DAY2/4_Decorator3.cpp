// Decorator - 65 page
#include <iostream>

class PhotoSticker
{
public:
	void take() { std::cout << "take Photo\n"; }
	void draw() { std::cout << "draw Photo\n"; }
};

/*
	 ���� ��ǥ�� ���� �����ϴ� ��ü�� �߰��ϴ� ��.

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

// ���� �׸� ����� �߰��ϴ� Ŭ����
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
	Frame f(&e);			// ����� ��ø
							// ���� code������ error, �ذ��� ���� �ҽ�����
	f.draw();
}
