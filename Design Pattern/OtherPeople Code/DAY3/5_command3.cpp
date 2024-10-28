#include "monitor.h"

// command ���� 
// => ����� ĸ��ȭ �Ѵ�.
// => � ���� �����ϰ� �ϴ� Ŭ������ ����� ��


// �޴�, ��ư ���� �����ϸ� ����� �ؾ� �մϴ�.

// C��� : �����ϰų�, �Լ��� ȣ���մϴ�.
//		   => "� ��"�� �Ҽ� �ֽ��ϴ�.

// Command ���� : �ش��ϴ� ���� �ϴ� Ŭ������ ������ ��
//		   => "� ��"�� �ϰ�
//		   => "���" �� ���� �ڵ嵵 ����� �ְ�
//         => "��Ҹ� ���� ����Ÿ" �� ����
//		   => "���� ���ƿ��� ���డ�������� ���絵 ����"
//			   Ŭ�����忡 ����Ÿ�� ������ "�ٿ��ֱ�"�� �ȵ�

// �پ��� ����� ������ �����Ƿ� �������̽� ����
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

	// #1. �� ���� ���� �ϰų�
	int old_value = m.get_brightness();
	m.set_brightness(90);  // A
	// ���⼭ ����� m �� A�� ���� ���� ���·� ������ ������
	m.set_brightness(? );




	// #2. Command ���� ���
	BrightCommand cmd(m, 90);
	cmd.execute();
	cmd.undo();
}