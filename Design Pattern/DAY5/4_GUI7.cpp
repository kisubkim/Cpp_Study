// x86 으로 build 해야함

#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

/*
	스마트 폰의 GUI를 개발한다고 생각을 해보자.
	처음에 MainWindow를 만들었고, 특정 위치에서 mouse click 했을 때 반드시 처리해야할 
	중요한 proc 가 있다고 해보자.

	그런데 UI 개선을 위해서 ImageWindow 를 추가하면,
	mouse click 을 처리하는 부분은 child window 인 ImageWindow 다.
	-> 만약에 그냥 기존 mainwindow 의 mouse click 에서 처리하는 부분을 child에서 처리했다고 치자

	나중에 시간이 지나서 다시 image 걷어내면 어케할껀데?

	그래서 chain of responsibility 를 사용해야함. (부모쪽으로 책임 전가)

*/

class Window {
	int handle;
	inline static std::map<int, Window*> this_map;

	Window* parent = nullptr;
	std::vector<Window*> child_vector;
public:

	void add_child(Window* child) {
		child->parent = this;
		child_vector.push_back(child);

		ec_add_child(this->handle, child->handle);
		ec_set_window_rect(child->handle, 100, 100, 200, 200);
	}

	void create(const std::string& title) {
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b) {
		Window* self = this_map[hwnd];

		switch (msg) {
		case WM_LBUTTONDOWN: 
			self->fire_lbutton_down();
			break;
		case WM_KEYDOWN:
			self->keydown();
			break;
		}
		return 0;
	}

	// 아래 코드가 "팩임의 고리 패턴"의 핵심
	void fire_lbutton_down() {
		// 1. 자신이 먼저 처리
		if (lbutton_down() == true) {
			return;
		}

		// 2. 처리 되지 않은 경우 부모에 전달.
		if (parent != nullptr) {
			parent->fire_lbutton_down();
		}
	}
	
	virtual bool lbutton_down() { return false; }		// override 하지 않으면 false return;
	virtual void keydown() {}
};

class MainWindow : public Window {
public:
	bool lbutton_down() override {
		std::cout << "MainWindow lbutton_down()\n";
		return true;
	}

	void keydown() override {
		std::cout << "MainWindow keydown\n";
	}
};

class ImageWindow : public Window {
public:
	bool lbutton_down() override {
		std::cout << "ImageWindow lbutton_down()\n";

		// true : event proc를 종료해 달라
		// false : event 를 parent에도 보내달라
		return false;
	}

	void keydown() override {
		std::cout << "ImageWindow keydown\n";
	}
};

int main()
{
	MainWindow w;
	w.create("MainWindow");

	ImageWindow w2;
	w2.create("ImageWindow");

	w.add_child(&w2);

	ec_process_message();
}

/*
	C# WPF 는 위와 같은 이벤트 처리를 "Bubbling Event" 라고 부름.

	C++ MFC 는 "Command Routing" 이라고 하고

	Swift IOS : "Responder Chain" 이라고 함.
*/