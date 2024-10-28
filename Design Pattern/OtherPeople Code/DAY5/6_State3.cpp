#include <iostream>

// 원하는 것 : 객체에 상태에 따라 거의 모든 멤버 함수를 교체하는것
// 아이템이 없을때 "멤버 함수들"
// 아이템이 있을때 "멤버 함수들"

// 멤버 함수들의 인터페이스
struct IState
{
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// 이외에 jump(), slide(), fly() ....
};

// 동작(멤버 함수)만 가지는 클래스들을 별도로 설계
class NoItem : public IState
{
public:
	void run() override { std::cout << "run" << std::endl; }
	void attack() override { std::cout << "attack" << std::endl; }
};

class SuperItem : public IState
{
public:
	void run() override { std::cout << "fast run" << std::endl; }
	void attack() override { std::cout << "power attack" << std::endl; }
};

class RedItem : public IState
{
public:
	void run() override { std::cout << "slower run" << std::endl; }
	void attack() override { std::cout << "super power attack" << std::endl; }
};

class Character
{
	int gold;
	int item;

	// 결국 아래 효과는 멤버함수 3개의 세트 를 가지고 있는것
	NoItem noitem;
	SuperItem superitem;
	RedItem reditem;

	IState* current = &noitem;

public:
	void acquire_super_item()
	{
		current = &superitem;

		// 타이머설치해서 3초뒤에
		// current = &noitem;
	}

	void run() { current->run(); }
	void attack() { current->attack(); }
};
int main()
{
	Character* p = new Character;
	p->run();
	p->attack();

	p->acquire_super_item();

	p->run();
	p->attack();

}


