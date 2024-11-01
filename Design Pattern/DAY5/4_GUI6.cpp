// x86 으로 build 해야함

#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

/*
	자식윈도우 개념을 추가해 보자.
*/

class Window {
	int handle;
	inline static std::map<int, Window*> this_map;

	Window* parent = nullptr;				// 부모 윈도우는 한개
	std::vector<Window*> child_vector;		// 자식 윈도우는 여러개
public:

	void add_child(Window* child) {
		child->parent = this;
		child_vector.push_back(child);

		// 실제 GUI의 자식 윈도우 부착은 c함수 사용
		ec_add_child(this->handle, child->handle);
		ec_set_window_rect(child->handle, 100, 100, 200, 200);		// 요거는 제대로 보기 위해서 임의로 추가한 내용임.
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
			self->lbutton_down();
			break;
		case WM_KEYDOWN:
			self->keydown();
			break;
		}
		return 0;
	}
	
	virtual void lbutton_down() {}
	virtual void keydown() {}
};

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

	w.add_child(&w2);

	ec_process_message();
}

