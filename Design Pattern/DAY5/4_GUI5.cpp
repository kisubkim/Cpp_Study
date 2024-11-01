// x86 으로 build 해야함

#define USING_GUI
#include "cppmaster.h"
#include <map>

/*
	여기서는 handle을 key 값으로 해서 this를 저장했다가 다시 꺼내는 방식으로 처리.
	위의 생각을 할 수 있어야 함.
*/

class Window;


std::map<int, Window*> this_map;

class Window {
	int handle;
public:
	void create(const std::string& title) {
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b) {
		Window* self = this_map[hwnd];

		/*
			이제 self(this)만 있으면 static 멤버 함수에서도 모든 멤버 접근이 가능함.
		*/
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
	// virtual void lbutton_down() = 0;
	// virtual void keydown() = 0;
	virtual void lbutton_down() {}
	virtual void keydown() {}
};

// 위 클래스는 "Library 설계자"가 제공
// 실제 사용자는 아래처럼 사용
class MainWindow : public Window {
public:
	void lbutton_down() override {
		std::cout << "MainWindow lbutton_down()\n";
	}

	void keydown() override {
		std::cout << "MainWindow keydown\n";
	}
};

class ImageWindow : public Window {
public:
	void lbutton_down() override {
		std::cout << "ImageWindow lbutton_down()\n";
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

	ec_process_message();
}

