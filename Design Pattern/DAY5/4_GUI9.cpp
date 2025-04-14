// x86 으로 build 해야함

#define USING_GUI
#include "cppmaster.h"
#include <map>

/*
	★★★Template 을 사용할 때는 T를 사용하는 함수와 사용하지 않는 함수를 분리 시킨다!!!★★★

	클래스 템플릿 만들 때
		T를 사용하지 않는 멤버는 템플릿이 아닌 기반 클래스를 만들고, 그곳에서 작성 해야함.
			==> ★ "Thin Template" or "Template hositing" 이라는 이름을 가진 기술임.★
			    template 사용 시 code memory 를 줄이기 위해 사용되는 기술.


	사용하는 녀석들은 template 들어간 녀석을 상속받아서 사용.
	그래야 template 에서 자동으로 만들어 주는 code memory를 줄일 수 있음.
*/


class Window {		// template 이 아님.
protected:
	int handle;
	inline static std::map<int, Window*> this_map;
public:
	void lbutton_down() {}
	void keydown() {}
};

template<typename T>
class MsgWindow : public Window {
public:
	void create(const std::string& title) {
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b) {
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg) {
		case WM_LBUTTONDOWN: 
			self->lbutton_down();
			break;
		case WM_KEYDOWN:
			self->keydown();
			break;
		}
		return 0;
	}
	
};

class MainWindow : public MsgWindow<MainWindow> {
public:
	void lbutton_down() {
		std::cout << "MainWindow lbutton_down()\n";
	}
};

int main()
{
	MainWindow w;
	w.create("MainWindow");

	ec_process_message();
}

