// x86 ���� build �ؾ���

#define USING_GUI
#include "cppmaster.h"
#include <map>

/*
	�ڡڡ�Template �� ����� ���� T�� ����ϴ� �Լ��� ������� �ʴ� �Լ��� �и� ��Ų��!!!�ڡڡ�

	Ŭ���� ���ø� ���� ��
		T�� ������� �ʴ� ����� ���ø��� �ƴ� ��� Ŭ������ �����, �װ����� �ۼ� �ؾ���.
			==> �� "Thin Template" or "Template hositing" �̶�� �̸��� ���� �����.��
			    template ��� �� code memory �� ���̱� ���� ���Ǵ� ���.


	����ϴ� �༮���� template �� �༮�� ��ӹ޾Ƽ� ���.
	�׷��� template ���� �ڵ����� ����� �ִ� code memory�� ���� �� ����.
*/


class Window {		// template �� �ƴ�.
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

