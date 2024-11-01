// x86 ���� build �ؾ���

#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

/*
	����Ʈ ���� GUI�� �����Ѵٰ� ������ �غ���.
	ó���� MainWindow�� �������, Ư�� ��ġ���� mouse click ���� �� �ݵ�� ó���ؾ��� 
	�߿��� proc �� �ִٰ� �غ���.

	�׷��� UI ������ ���ؼ� ImageWindow �� �߰��ϸ�,
	mouse click �� ó���ϴ� �κ��� child window �� ImageWindow ��.
	-> ���࿡ �׳� ���� mainwindow �� mouse click ���� ó���ϴ� �κ��� child���� ó���ߴٰ� ġ��

	���߿� �ð��� ������ �ٽ� image �Ⱦ�� �����Ҳ���?

	�׷��� chain of responsibility �� ����ؾ���. (�θ������� å�� ����)

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

	// �Ʒ� �ڵ尡 "������ �� ����"�� �ٽ�
	void fire_lbutton_down() {
		// 1. �ڽ��� ���� ó��
		if (lbutton_down() == true) {
			return;
		}

		// 2. ó�� ���� ���� ��� �θ� ����.
		if (parent != nullptr) {
			parent->fire_lbutton_down();
		}
	}
	
	virtual bool lbutton_down() { return false; }		// override ���� ������ false return;
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

		// true : event proc�� ������ �޶�
		// false : event �� parent���� �����޶�
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
	C# WPF �� ���� ���� �̺�Ʈ ó���� "Bubbling Event" ��� �θ�.

	C++ MFC �� "Command Routing" �̶�� �ϰ�

	Swift IOS : "Responder Chain" �̶�� ��.
*/