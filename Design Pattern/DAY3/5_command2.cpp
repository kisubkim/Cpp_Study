#include "monitor.h"

/*
	모니터의 밝기를 변경하려면
		1. 밝기를 변경하는 멤버 함수를 직접 호출
		2. 모니터의 밝기를 변경하는 일을 하는 객체 사용 - Command Pattern

	어떤 일을 하는 함수(멤버함수)를 직접호출하면 => "해당하는 일" 만 수행

	Command Pattern : 해당하는 일을 수행하는 객체를 만들면
		=> "해당하는 일" 도 수행하고
		=> "취소를 위한 데이터 보관" 도 가능하고
		=> "취소 하는 코드를 제공" 할 수도 있고
		=> "현재 상태에서 취소가 가능" 한지 조사도 가능
		=> 네트워크 전송된 데이터는 취소 안됨.


	WPF의 경우 메뉴에 어떤 메뉴를 추가하고자 하면 class를 만들어라 함.
	왜냐? 이건 Command Pattern으로 이루어져 있기 때문임.
*/


class BrightCommand {
	Monitor& m;
	int value;
	int old = 0;
public:
	BrightCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() {
		old = m.get_brightness();
		m.set_brightness(value);
	}

	void undo() {
		m.set_brightness(old);
	}
};

int main()
{
	Monitor m;

	int old = m.get_brightness();
	m.set_brightness(90);			// 직접 변경
	
	// m의 밝기 상태를 이전 사애로 복구해 보자!
	m.set_brightness(old);

	BrightCommand cmd(m, 90);		// 객체 사용
	cmd.execute();
	cmd.undo();						// 위처럼 할 필요 없이 command 객체 내부에 undo()를 넣으면 됨.
}