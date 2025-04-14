#include <iostream>

/*
	Chain of Responsibility
		=> 책임의 고리(연쇄, 전달)로 번역!
		=> 다양하게 활용되는데, 잘 알려지지 않은 패턴.

	설명
		울 회사 AS center가 있다고 해보자.
		폰을 고칠려고 찾아 갔더니 
			1. 안내데스크에서 저기 고치는 데로 가세요~ 하면서 나를 절로 보냄
			2. 갔던 곳이 베터리 고치는 팀이었는데 베터리는 문제 없다함. 메모리 고치는 곳으로 가라함
			3. 메모리 고치는 곳으로 갔더니...이상이 없다고 SW 쪽으로 가라고 함
			4. SW 담당팀에서 update 하라함..

		결국, 문제 발생하면 고칠때까지 계속 어디로 이동하면서 확인함.

	핵심
		문제가 발생하면
			1. 1st 객체가 처리를 시도
			2. 처리하지 못하고 next가 있으면 next 로 전달
			3. next Object가 1번 항목을 반복.
			4. 이동하다가 처리하면 끝.
*/


// 아래 코드가 "책임의 전가 패턴의 핵심" 임.
struct Handler
{
	Handler* next = nullptr;

	// 특히 요부분!
	void Handle(int problem)
	{
		// 1. 자신이 처리를 시도.
		if (HandleRequest(problem) == true)
			return;

		// 2. 못했고, next 있으면 toss
		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};

class Team1 : public Handler {
public:
	bool HandleRequest(int problem) {
		std::cout << "Start Team1\n";
		if (problem == 7) {
			std::cout << "Resolved by Team1\n";
			return true;
		}
		return false;
	}
};

class Team2 : public Handler {
public:
	bool HandleRequest(int problem) {
		std::cout << "Start Team2\n";
		if (problem % 2 == 0) {
			std::cout << "Resolved by Team2\n";
			return true;
		}
		return false;
	}
};

class Team3 : public Handler {
public:
	bool HandleRequest(int problem) {
		std::cout << "Start Team2\n";
		if (problem < 10) {
			std::cout << "Resolved by Team2\n";
			return true;
		}
		return false;
	}
};


class Team2 : public Handler {
public:
	bool HandleRequest(int problem) {
		std::cout << "Start Team2\n";
		if (problem % 2 == 0) {
			std::cout << "Resolved by Team2\n";
			return true;
		}
		return false;
	}
};

class Team3 : public Handler {
public:
	bool HandleRequest(int problem) {
		std::cout << "Start Team2\n";
		if (problem < 10) {
			std::cout << "Resolved by Team2\n";
			return true;
		}
		return false;
	}
};

int main()
{
	Team1 t1;
	Team2 t2;
	Team3 t3;

	t1.next = &t2;
	t2.next = &t3;
	t3.next = 0;

	// 문제가 발생하면 1번팀에 전달
	//t1.Handle(7);		// Team1 이 해결
	//t1.Handle(20);	// Team2 가 해결
	//t1.Handle(5);		// Team3 이 해결
	t1.Handle(15);		// 해결 안됨.
}
