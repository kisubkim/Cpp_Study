#include <iostream>

/*
	Item �� 3���� ���۵� 3�� �־����.
	��, ��� ���� �Լ��� "3����" �־�� ��.
	"run", "attack", etc. ��� �Լ��� 3���� ������.
*/

struct IState {
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// slide(), jump(), fly() ��� ��� �����Լ� ����.
};

// ���� �� Item ���� ������ ���� ����
class NoItem : public IState {
public:
	void run() override {
		std::cout << "run" << std::endl;
	}

	void attack() override {
		std::cout << "attack" << std::endl;
	}
};

class Item1 : public IState {
public:
	void run() override {
		std::cout << "fast run" << std::endl;
	}

	void attack() override {
		std::cout << "power attack" << std::endl;
	}
};

class Item2 : public IState {
public:
	void run() override {
		std::cout << "super fast run" << std::endl;
	}

	void attack() override {
		std::cout << "super power attack" << std::endl;
	}
};

class Character
{
	NoItem state1;
	Item1 state2;
	Item2 state3;

	IState* state = &state1;

	int gold;
	int item;
public:
	void run() { state->run(); }
	void attack() { state->attack(); }
	void acquire_item1() {
		state = &state2;

		// timer ��ġ �� 3�еڿ� ȣ��Ǵ� �Լ����� �ٽ� normal ��
		// state = &state1;
	}


};

int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->acquire_item1();
	/*
		�ǹ�
			1. p �� ���� (��� ������)�� ��� ������.
			2. �� ���� ��� ��� �Լ��� ��ü��.
				=> ��ġ �ٸ� Ŭ���� ó�� ���̰� ��. "State Pattern"
	*/

	p->run();
	p->attack();
}

/*
	���Ǳ⸦ ������ ����.
		>> ���Ǳ�� �� �־��� ���� ���� �ʾ��� �� ������ �ٸ�.
		>> ������ 2�� �غ��ϰ�, �� ������ ��ü!
		>> �� �̾ư��� �ٽ� ��ü!

		>> ��.��.�� ���� Data�� ����!!

	Strategy Pattern �� ������ ����. �׷��� �Ƹ� �ǵ��� �ٸ� �� ����� ��.
*/

