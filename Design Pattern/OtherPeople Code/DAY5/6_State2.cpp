#include <iostream>

// ������ ĳ���͸� ������ ���ô�.
// Item ȹ�濡 ���� ���� ĳ������ �پ��� ������ �����ϰ� �ʹ�.
class Character
{
	int gold;
	int item;
public:
	void run() { std::cout << "run" << std::endl; }
	void attack() { std::cout << "attack" << std::endl; }
};
int main()
{
	Charatcer* p = new Character;
	p->run();
	p->attack();
}



