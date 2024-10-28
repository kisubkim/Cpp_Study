#include <iostream>

// ��� ������ ��Ʈ���� ������ ��� Ŭ���� �ʿ�
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
// ��Ÿ�� ���� ��Ʈ���� �̸��� �����ϴ� Ÿ��(����ü)�� ����� ���ô�.
// => ��� ����Ÿ�� ����Լ��� ����, ���� Ŭ���� �̸�(����)�� ���� ����ü
struct Windows
{
	using Button = WinButton;
	using Edit = WinEdit;

	// �׿� ��� Windows ��Ʈ�� �̸�
};

struct OSX
{
	using Button = OSXButton;
	using Edit = OSXEdit;
};



// Ÿ��::�̸� ���� "�̸�"��
// 1. static ��� ����Ÿ - ��
// 2. nested Ÿ�� �ϼ� �ֽ��ϴ�.
// � �����Ŀ� ���� * ���� ���� �ǹ̰� �޶� ���ϴ�.

/*
class AA
{
public:
	static int Data;
	using type = int;
};
AA::Data * p   ���� * �� ���ϱ�
AA::type * p   ���� * �� ������ ���� p ����
*/

// "AA::type" ���� ǥ���ϸ� �����Ϸ��� "AA class " �� �����Ҽ� �ֽ��ϴ�.
// "T::type"  ���� �ϸ� �����Ϸ��� �����Ҽ� �����ϴ�.
// �׷���
// "T::type" �ϸ� type �� ������ �ؼ�
// "typename T::type" �ϸ� type �� Ÿ������ �ؼ�

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



