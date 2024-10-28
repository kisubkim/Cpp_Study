#define USING_GUI
#include "cppmaster.h"
#include <map>
#include <vector>

class Window;
std::map<int, Window*> this_map;

class Window
{
	int handle;
	Window* parent = nullptr;
	std::vector<Window*> child_vector;
public:

	void add_child(Window* child) {
		child->parent = this;
		child_vector.push_back(child);

		ec_add_child(this->handle, child->handle);
	}

	void create(const std::string& title)
	{
		handle = ec_make_window(&msgproc, title);
		this_map[handle] = this;
		//this를 자료구조에 넣을수가있다.
	}

	static int msgproc(int hwnd, int msg, int a, int b)
	{
		Window* self = this_map[hwnd];
		switch (msg)
		{
		case WM_LBUTTONDOWN: self->handle_lbutton_down(); break; //일반 멤버함수 부르지 못함 (static 이기때문에)
		case WM_KEYDOWN:     self->handle_key_down();     break; //this->lbutton_down을 알지 못함.
		}
		return 0;
	}

	void handle_lbutton_down() {
		if (lbutton_down() == true)
			return;
		if (parent != nullptr)
			parent->handle_lbutton_down();
	}

	void handle_key_down() {
		if (key_down() == true)
			return;
		if (parent != nullptr)
			parent->handle_key_down();
	}

	virtual bool lbutton_down() { return false; }
	virtual bool key_down() { return false; }
};

class MainWindow : public Window
{
public:
	bool lbutton_down() override
	{
		std::cout << "MainWindow lbutton_down\n";
		return true;
	}
};

class ImageView : public Window
{
public:
	bool lbutton_down() override {
		std::cout << "ImageView lbutton down\n";
		return false;
	}
};

int main()
{
	MainWindow w1;
	ImageView w2;
	w1.create("1차 월맹군");
	w2.create("2차 월맹군");

	w1.add_child(&w2);

	ec_process_message();
}