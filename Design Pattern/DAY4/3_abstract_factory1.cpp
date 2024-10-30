// 3_추상팩토리 - 147
#include <iostream>

/*
	QT Library : 프로그램 실행 시 Lock and feel 변경 기능이 있음.

*/



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

int main(int argc, char** argv)
{
	IButton* btn;		// 모든 종류 버튼의 기반 클래스
	if (strcmp(argv[1], "-style:OSX") == 0)
		btn = new OSXButton;
	else
		btn = new WinButton;

	// 그런데 프로그램에서 버튼은 한개만 만들게 될까?
	//	=> 매번 위처럼 코딩은 힘듬.
	//	=> 결론은 공장에서 찍어내야함.
}








