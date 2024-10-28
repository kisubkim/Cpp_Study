#include "monitor.h"

// command 패턴 
// => 명령을 캡슐화 한다.
// => 어떤 일을 수행하게 하는 클래스를 만드는 것


// 메뉴, 버튼 등을 선택하면 어떤일을 해야 합니다.

// C언어 : 직접하거나, 함수를 호출합니다.
//		   => "어떤 일"만 할수 있습니다.

// Command 패턴 : 해당하는 일을 하는 클래스를 만들라는 것
//		   => "어떤 일"도 하고
//		   => "취소" 을 위한 코드도 만들수 있고
//         => "취소를 위한 데이타" 도 보관
//		   => "현재 문맥에서 실행가능한지도 조사도 가능"
//			   클립보드에 데이타가 없으면 "붙여넣기"는 안됨

// 다양한 명령이 있을수 있으므로 인터페이스 부터
struct ICommand
{
	virtual void execute() = 0;
	virtual void undo() = 0;
	virtual ~ICommand() {}
};

class BrightCommand : public ICommand
{
	Monitor& m;
	int value;
	int old_value;
public:
	BrightCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute()
	{
		old_value = m.get_brightness();
		m.set_brightness(value);
	}
	void undo()
	{
		m.set_brightness(old_value);
	}
};

int main()
{
	Monitor m;

	// #1. 그 일을 직접 하거나
	int old_value = m.get_brightness();
	m.set_brightness(90);  // A
	// 여기서 모니터 m 을 A의 실행 이전 상태로 복구해 보세요
	m.set_brightness(? );




	// #2. Command 패턴 사용
	BrightCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();
}