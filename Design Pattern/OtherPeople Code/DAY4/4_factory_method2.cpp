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

class BaseDialog
{
public:
	// 결국 Dialog 를 만드는 과정과 동작은 동일합니다.
	// => 그런데, 각 Style 옵션에 따라 컨트롤의 타입만 변경됩니다.
	void init()
	{
		IButton* btn = CreateButton();
		IEdit* edit = CreateEdit();

		// btn->Move(); edit->Move();

		btn->Draw();
		edit->Draw();
	}
	// 객체를 생성하기 위한 인터페이스를 제공하고, 사용하지만
	// 어떤 객체를 생성할지는 파생 클래스가 결정한다.
	// template method  와 동일한 모양이지만
	// 객체를 생성하기 위해 사용한다는 의미로 "factory method" 라고 합니다.
	virtual IButton* CreateButton() = 0;
	virtual IEdit* CreateEdit() = 0;
};


// Style 옵션과 상관없이 항상 Windows 모양의 Dialog

class WinDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new WinButton; }
	IEdit* CreateEdit()     override { return new WinEdit; }
};
class OSXDialog : public BaseDialog
{
public:
	IButton* CreateButton() override { return new OSXButton; }
	IEdit* CreateEdit()     override { return new OSXEdit; }
};

int main(int argc, char** argv)
{

}
