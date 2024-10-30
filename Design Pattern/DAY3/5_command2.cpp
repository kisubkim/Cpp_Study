#include "monitor.h"

/*
	������� ��⸦ �����Ϸ���
		1. ��⸦ �����ϴ� ��� �Լ��� ���� ȣ��
		2. ������� ��⸦ �����ϴ� ���� �ϴ� ��ü ��� - Command Pattern

	� ���� �ϴ� �Լ�(����Լ�)�� ����ȣ���ϸ� => "�ش��ϴ� ��" �� ����

	Command Pattern : �ش��ϴ� ���� �����ϴ� ��ü�� �����
		=> "�ش��ϴ� ��" �� �����ϰ�
		=> "��Ҹ� ���� ������ ����" �� �����ϰ�
		=> "��� �ϴ� �ڵ带 ����" �� ���� �ְ�
		=> "���� ���¿��� ��Ұ� ����" ���� ���絵 ����
		=> ��Ʈ��ũ ���۵� �����ʹ� ��� �ȵ�.


	WPF�� ��� �޴��� � �޴��� �߰��ϰ��� �ϸ� class�� ������ ��.
	�ֳ�? �̰� Command Pattern���� �̷���� �ֱ� ������.
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
	m.set_brightness(90);			// ���� ����
	
	// m�� ��� ���¸� ���� ��ַ� ������ ����!
	m.set_brightness(old);

	BrightCommand cmd(m, 90);		// ��ü ���
	cmd.execute();
	cmd.undo();						// ��ó�� �� �ʿ� ���� command ��ü ���ο� undo()�� ������ ��.
}