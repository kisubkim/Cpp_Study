// 6_Mediator - 중재자 패턴 
#include <iostream>

/*
	만약 어디 가입할 때 popup 창 생각해보자.
	읽었는지 확인하는 check box 를 check 하지 않으면 "가입" Button 못누름.

	이때 Check box를 생각하면 됨.
*/

class CheckBox
{
	bool state;
public:
	CheckBox() : state(false) {}
	
	void SetCheck(bool b) { state = b; ChangeState(); }
	bool GetCheck()       { return state; }

	virtual void ChangeState() {}
};
class MyCheckBox : public CheckBox
{
public:
	void ChangeState() override
	{
		if (GetCheck() == true) {
			std::cout << "enable button\n";
		}
		else {
			std::cout << "disable button\n";
		}
	}
};


int main()
{
	MyCheckBox c;
	c.SetCheck(true);
}



