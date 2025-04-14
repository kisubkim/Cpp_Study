// x86 으로 build 해야함

#define USING_GUI
#include "cppmaster.h"

/*
	아래 windows class는 library 가 되어야 한다고 생각하면
	msgproc() 내부에서 전체적인 flow 는 변하지 않지만, 그 flow 에서 해야 하는 동작은 
	변할 수 있도록 해야함 ==> 가상함수로 분리!
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
			lbutton_down();		// 멤버 함수는 "객체.함수()" 가 되어야 하는데...
								// 따라서 이 코드는 "this->lbutton_down()" 이 되어야 함.
								// 그런데, static 멤버 함수에서는 this가 없기 때문에 member function 을 사용할 수가 없음.
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

