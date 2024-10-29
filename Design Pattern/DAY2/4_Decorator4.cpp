// Decorator - 65 page
#include <iostream>

/*
	Ŭ������ Ŭ������ "����� �߰��ϴ� Ŭ����(Decorator)"
	�� ������ ��� Ŭ������ �־�� "��ø�� ����߰�"�� ������.

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

// ���� �׸� ����� �߰��ϴ� Ŭ����
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
	f.draw();		// ��� �߰��� ���� ���.

	ps.draw();		// ��� �߰� ���� ��ü�� ��밡��.


	// ���� ������ ����
	// �Ʒ�ó�� fillter �������� �ϸ� �ȵǳ���??

	/*
	PhotoSticker ps;
	ps.take();

	ps.add_filter(new Emoticion);
	ps.add_filter(new Frame);

	ps.draw();		// ��ϵ� ���͸� ��� ����ϰ� �Կ��� ���� ���.
	// �� ���� "���� �׸��� ���" �ϴ� ����� ����.
	// ==> ���͸� �����ϰ� �׷�����.
	*/
}
