// x86 ���� build �ؾ���

#define USING_GUI
#include "cppmaster.h"
#include <map>

/*
	���⼭�� handle�� key ������ �ؼ� this�� �����ߴٰ� �ٽ� ������ ������� ó��.
	���� ������ �� �� �־�� ��.
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
			���� self(this)�� ������ static ��� �Լ������� ��� ��� ������ ������.
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

// �� Ŭ������ "Library ������"�� ����
// ���� ����ڴ� �Ʒ�ó�� ���
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

