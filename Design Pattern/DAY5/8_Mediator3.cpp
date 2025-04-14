#include <iostream>
#include <conio.h>

/*
	가입창을 보면, 모든 필수 항목이 차있어야 가입 버튼을 누를 수 있음.

	이때, 각 Controlor 들은 각자 자신이 값이 있다고 중재자(mediator)에게 알려주고,
	중재자가 가입 버튼 활성화 여부를 판단한다.
*/

// 중재자의 인터페이스
struct IMediator
{
	virtual void ChangeState() = 0;
	virtual ~IMediator() {}
};

class CheckBox
{
	bool state;

	IMediator* pMediator; // 모든 협력자(Colleague)는 중재자를 알아야 합니다.
public:
	void SetMediator( IMediator* p ) { pMediator = p; }

	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState();
							pMediator->ChangeState(); }

	bool GetCheck()       { return state; }
	virtual void ChangeState() {}
};

class RadioBox
{
	bool state;

	IMediator* pMediator; // 모든 협력자(Colleague)는 중재자를 알아야 합니다.
public:
	void SetMediator( IMediator* p ) { pMediator = p; }

	RadioBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState();
							pMediator->ChangeState(); }

	bool GetCheck()       { return state; }
	virtual void ChangeState() {}
};

// 중재자 클래스
// 중재자는 모든 협력자(Collegue)를 알고 잇어야 합니다.
class LogInMediator : public IMediator
{
	CheckBox* c1;
	CheckBox* c2;
	RadioBox* r1;
	RadioBox* r2;
public:
	LogInMediator( CheckBox* a, CheckBox* b, RadioBox* c, RadioBox* d)
		: c1(a), c2(b), r1(c), r2(d)
	{
		c1->SetMediator(this);
		c2->SetMediator(this);
		r1->SetMediator(this);
		r2->SetMediator(this);
	}
	void ChangeState()
	{
		// 이제 모든 협력자의 관계설정은 이곳에 집중됩니다.
		if ( c1->GetCheck() && c2->GetCheck() &&
			 r1->GetCheck() && r2->GetCheck())
		{
			 std::cout <<"버튼 Enable" << std::endl;
		}
		else
			std::cout << "버튼 disable" << std::endl;
	}
};


int main()
{
	// Dialog 위의 모든 control
	//		=> 핵심 : control 은 서로를 알 필요없음.
	CheckBox c1, c2;
	RadioBox r1, r2;

	// 각 control 의 상태가 변경될 때 통보될 "중재자 객체"
	//		=> 중재자는 모든 컨트롤(협력자)를 알아야 한다.
	LogInMediator m(&c1, &c2, &r1, &r2);

	_getch(); c1.SetCheck(true);
	_getch(); c2.SetCheck(true);
	_getch(); r1.SetCheck(true);
	_getch(); r2.SetCheck(true);
	_getch(); c1.SetCheck(false);
}









