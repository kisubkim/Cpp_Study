// x86 ���� build �ؾ���

#define USING_GUI
#include "cppmaster.h"

/*
	�Ʒ� windows class�� library �� �Ǿ�� �Ѵٰ� �����ϸ�
	msgproc() ���ο��� ��ü���� flow �� ������ ������, �� flow ���� �ؾ� �ϴ� ������ 
	���� �� �ֵ��� �ؾ��� ==> �����Լ��� �и�!
*/

class Window {
	int handle;
public:
	void create(const std::string& title) {
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
	}

	static int msgproc(int hwnd, int msg, int a, int b) {
		switch (msg) {
		case WM_LBUTTONDOWN: 
			lbutton_down();		// ��� �Լ��� "��ü.�Լ�()" �� �Ǿ�� �ϴµ�...
								// ���� �� �ڵ�� "this->lbutton_down()" �� �Ǿ�� ��.
								// �׷���, static ��� �Լ������� this�� ���� ������ member function �� ����� ���� ����.
			break;
		case WM_KEYDOWN:
			keydown();
			break;
		}
		return 0;
	}

	virtual void lbutton_down() = 0;
	virtual void keydown() = 0;
};

int main()
{
	Window w;
	w.create("Title");

	ec_process_message();
}

