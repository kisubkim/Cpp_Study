#include <iostream>

struct Handler
{
	Handler* next = nullptr;

	Handler* set_next(Handler* n)
	{
		next = n;
		return next;
	}

	// 아래 함수가 핵심
	void Handle(int problem)
	{
		// #1. 자신이 먼저 처리를 시도
		if (HandleRequest(problem) == true)
			return;

		if (next != 0)
			next->Handle(problem);
	}

	virtual bool HandleRequest(int problem) = 0;
};

class Team1 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Team1 Start\n";

		if (problem == 7)
		{
			std::cout << "resolved by Team1\n";
			return true;
		}
		return false;
	}
};

class Team2 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Team2 Start\n";

		if (problem % 2 == 0)
		{
			std::cout << "resolved by Team2\n";
			return true;
		}
		return false;
	}
};

class Team3 : public Handler
{
public:
	bool HandleRequest(int problem) override
	{
		std::cout << "Team3 Start\n";

		if (problem < 10)
		{
			std::cout << "resolved by Team3\n";
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

	t1.set_next(&t2)->set_next(&t3);

	//  t1.Handle(7);
	//	t1.Handle(8);
	//	t1.Handle(3);
		t1.Handle(13);
}
