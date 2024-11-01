// x86 으로 build 해야함

/*
	1. 대부분의 OS 는 GUI를 만들기 위한 함수 제공 (C 언어기능)
	2. GUI Programe 을 만드는 가장 기본적인 방법은 "C함수" 사용
	3. 그런데, C함수를 직접 사용하면 아주 복잡함.
*/
#define USING_GUI
#include "cppmaster.h"

// event 처리함수 조건 : 인자가 int 타입 4개
// msg : event 의 종류 code
// a, b : event param. event 의 추가적인 정보들.(ex> aschii code, mouse 좌표, etc.)
int foo(int hwnd, int msg, int a, int b) 
{
	switch (msg)
	{
	case WM_LBUTTONDOWN: std::cout << "LBUTTON" << hwnd << std::endl; break;
	case WM_KEYDOWN:     std::cout << "KEYDOWN" << hwnd << std::endl; break;
	}
	return 0;
}
int main()
{
	// Windows 에서 window를 만들면 숫자가 할당됨.
	// 이 숫자가 해당 window의 handle 이라고함.
	int h1 = ec_make_window(foo, "A"); 
	int h2 = ec_make_window(foo, "B");

	ec_set_window_rect(h1, 0, 0, 400, 400);
	ec_set_window_rect(h2, 100, 100, 40, 40);
	ec_add_child(h1, h2);		// h2를 h1의 자식으로

	ec_process_message();	// 종료되지 말고, 윈도우에서 발생하는 이벤트를 처리해 달라.
}

