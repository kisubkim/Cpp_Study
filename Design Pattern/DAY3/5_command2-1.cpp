#include "monitor.h"

struct ICommand {
	virtual void execute() = 0;
	virtual bool can_undo() { return false; }
	virtual void undo() {}

	virtual ~ICommand() {}
};

class BrightCommand : public ICommand {
	Monitor& m;
	int value;
	int old = 0;
public:
	BrightCommand(Monitor& m, int v) : m(m), value(v) {}

	void execute() override {
		old = m.get_brightness();
		m.set_brightness(value);
	}

	bool can_undo() override { return true; }

	void undo() override {
		m.set_brightness(old);
	}
};

int main()
{
	Monitor m;

	int old = m.get_brightness();
	m.set_brightness(90);			// 직접 변경
	
	m.set_brightness(old);

	BrightCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();
}