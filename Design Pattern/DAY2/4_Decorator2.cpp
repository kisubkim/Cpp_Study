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

// ����� ����� ����� �߰�
// ��� : ��ü�� �ƴ� Ŭ������ ����� �߰��� ��.
//		  ����ð�(����)���� �߰��� ���� �ƴ� �ҽ� �ۼ�(����) �ÿ� �߰��� ��.
class Emoticon{
	PhotoSticker* origin;		// �ٽ� : ������ �Ǵ� ���� ��� (��Ÿ�� �ƴ�)
								// �ǹ� : �̹� �����Ǿ� �ִ� ��ü�� ����Ű�ڴٴ� ��
public:
	Emoticon(PhotoSticker* ps) : origin(ps) {}
	void draw() {
		std::cout << "@@@@@@@@@@@@@@" << std::endl;
		origin->draw();
		std::cout << "@@@@@@@@@@@@@@" << std::endl;
	}
};


int main()
{
	PhotoSticker ps;
	ps.take();
	ps.draw();

	Emoticon e(&ps);		// ps��� �̹� ������ ��ü�� ����� �߰��ϴ� e ��ü
	e.draw();		// e�� �߰��� ����� ����ϰ� �ٽ� ps�� ����� ���

}
