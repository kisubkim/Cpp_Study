#include <iostream>

/*
	Item 이 3개면 동작도 3번 있어야함.
	즉, 모든 동작 함수도 "3개씩" 있어야 함.
	"run", "attack", etc. 모든 함수를 3개씩 만들자.
*/

struct IState {
	virtual void run() = 0;
	virtual void attack() = 0;
	virtual ~IState() {}

	// slide(), jump(), fly() 등등 모든 동작함수 선언.
};

// 이제 각 Item 별로 동작을 따로 설계
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

		// timer 설치 후 3분뒤에 호출되는 함수에서 다시 normal 로
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
		의미
			1. p 의 상태 (멤버 데이터)는 계속 유지됨.
			2. 이 순간 모든 멤버 함수가 교체됨.
				=> 다치 다른 클래스 처럼 보이게 됨. "State Pattern"
	*/

	p->run();
	p->attack();
}

/*
	자판기를 생각해 보자.
		>> 자판기는 돈 넣었을 때랑 넣지 않았을 때 완전히 다름.
		>> 동작을 2쌍 준비하고, 돈 들어오면 교체!
		>> 머 뽑아가면 다시 교체!

		>> 하.지.만 내부 Data는 유지!!

	Strategy Pattern 과 유사해 보임. 그런데 아마 의도가 다를 것 같기는 함.
*/

