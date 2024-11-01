// x86 으로 build 해야함

#define USING_GUI
#include "cppmaster.h"
#include <map>

/*
	가상 함수는 실행될 때 가상함수 테이블을 작성한다.
	그런데 이게 생각보다 메모리를 많이 먹음.

	Event 처리를 가상함수로 하면
		=> 가상함수 테이블의 오버헤드가 있음.
		=> 200개 가상함수 * 함수주소크기(8byte) => 1600 byte

	아래 코드가
		=> CRTP 를 사용해서 가상이 아닌 함수를 가상함수 처럼 동작하게 하는 기술
		=> MS 의 WTL 이 이렇게 설계
		=> C++20 Range Library 도 이 기술 사용.
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
			self->lbutton_down();		// 여기서 self의 type 이 Window 라서 window 함수가 call 됨.
			/*
				함수 호출
					가상함수 : dynamic binding (실행시간에 메모리 조사)
					비가상   : static binding (포인터 타입)
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

