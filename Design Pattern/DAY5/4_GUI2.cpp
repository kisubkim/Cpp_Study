// x86 으로 build 해야함

#define USING_GUI
#include "cppmaster.h"

int foo(int hwnd, int msg, int a, int b)
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}

class Window {
	int handle;		// window 번호(handle)
public:
	void create(const std::string& title) {
		handle = ec_make_window(foo, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
	}
};

int main()
{
	Window w;
	w.create("Title");		// 이 순간 윈도우가 생성되도록.

	ec_process_message();
}

