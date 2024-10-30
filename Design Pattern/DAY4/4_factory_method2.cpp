// 1번 복사해 오세요..
// 5_팩토리메소드
#include <iostream>

// 모든 종류의 컨트롤은 공통의 기반 클래스 필요
struct IButton
{
	virtual void Draw() = 0;
	virtual ~IButton() {}
};
struct IEdit
{
	virtual void Draw() = 0;
	virtual ~IEdit() {}
};


struct WinButton : public IButton
{
	void Draw() { std::cout << "Draw WinButton" << std::endl; }
};
struct WinEdit : public IEdit
{
	void Draw() { std::cout << "Draw WinEdit" << std::endl; }
};

struct OSXButton : public IButton
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
struct OSXEdit : public IEdit
{
	void Draw() { std::cout << "Draw OSXButton" << std::endl; }
};
//--------------------------------------

/*
	Factory method 가 아닌 template ver.

	각 style 별 control name만 관리하는 타입 설계

	타입을 여러개 보내야 하는 상황이 오면 전체 스타일에 대한 class를 하나 만들고
	해당 클래스 내부에는 각 스타일을 미리 정의해 두면 된다.
*/

struct WinStyle {
	using Button = WinButton;		// typedef WinButton Button
	using Edit = WinEdit;

	// 그 외 모든 control name을 제공.
};

struct OSXStyle {
	using Button = OSXButton;		// typedef OSXButton Button
	using Edit = OSXEdit;

	// 그 외 모든 control name을 제공.
};

template<typename T>
class Dialog {
public:
	void init()
	{
		// 이제 T는 Control의 이름이 아닌 컨트롤의 이름만 관리하는 타입.
		//		=>
		IButton* btn = new typename T::Button;
		IEdit* edit = new typename T::Edit;

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
};


int main(int argc, char** argv)
{
	Dialog<OSXStyle> dlg1;
	Dialog<WinStyle> dlg2;

	dlg1.init();
	dlg2.init();
}








