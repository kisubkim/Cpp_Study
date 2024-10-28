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
// 스타일 별로 컨트롤의 이름만 관리하는 타입(구조체)를 만들어 봅시다.
// => 멤버 데이타와 멤버함수는 없고, 오직 클래스 이름(별명)만 가진 구조체
struct Windows
{
	using Button = WinButton;
	using Edit = WinEdit;

	// 그외 모든 Windows 컨트롤 이름
};

struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;
};



// 타입::이름 에서 "이름"은
// 1. static 멤버 데이타 - 값
// 2. nested 타입 일수 있습니다.
// 어떤 종류냐에 따라서 * 등을 사용시 의미가 달라 집니다.

/*
class AA
{
public:
	static int Data;
	using type = int;
};
AA::Data * p   에서 * 는 곱하기
AA::type * p   에서 * 는 포인터 변수 p 선언
*/

// "AA::type" 으로 표기하면 컴파일러가 "AA class " 를 조사할수 있습니다.
// "T::type"  으로 하면 컴파일러는 조사할수 없습니다.
// 그래서
// "T::type" 하면 type 을 값으로 해석
// "typename T::type" 하면 type 을 타입으로 해석

template<typename T>
class Dialog
{
public:
	void init()
	{
		IButton* btn = new typename T::Button;
		IEdit* edit = new typename T::Edit;

		btn->Draw();
		edit->Draw();
	}
};

int main(int argc, char** argv)
{
	Dialog< Windows > dlg;

}



