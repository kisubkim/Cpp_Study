// x86 ���� build �ؾ���

#define USING_GUI
#include "cppmaster.h"
#include <map>

/*
	���� �Լ��� ����� �� �����Լ� ���̺��� �ۼ��Ѵ�.
	�׷��� �̰� �������� �޸𸮸� ���� ����.

	Event ó���� �����Լ��� �ϸ�
		=> �����Լ� ���̺��� ������尡 ����.
		=> 200�� �����Լ� * �Լ��ּ�ũ��(8byte) => 1600 byte

	�Ʒ� �ڵ尡
		=> CRTP �� ����ؼ� ������ �ƴ� �Լ��� �����Լ� ó�� �����ϰ� �ϴ� ���
		=> MS �� WTL �� �̷��� ����
		=> C++20 Range Library �� �� ��� ���.
*/



template<typename T>
class Window {
	int handle;
	inline static std::map<int, Window*> this_map;
public:
	void create(const std::string& title) {
		handle = ec_make_window(msgproc, title);
		ec_set_window_rect(handle, 0, 0, 500, 500);
		this_map[handle] = this;
	}

	static int msgproc(int hwnd, int msg, int a, int b) {
		//Window* self = this_map[hwnd];
		T* self = static_cast<T*>(this_map[hwnd]);

		switch (msg) {
		case WM_LBUTTONDOWN: 
			self->lbutton_down();		// ���⼭ self�� type �� Window �� window �Լ��� call ��.
			/*
				�Լ� ȣ��
					�����Լ� : dynamic binding (����ð��� �޸� ����)
					�񰡻�   : static binding (������ Ÿ��)
			*/
			break;
		case WM_KEYDOWN:
			self->keydown();
			break;
		}
		return 0;
	}
	void lbutton_down() {}
	void keydown() {}
};

class MainWindow : public Window<MainWindow> {
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

