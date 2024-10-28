#include "monitor.h"

void set_monitor_for_video(Monitor& m) {
	m.set_brightness(90);
	m.set_resolution(1920);
}

int main()
{
	Monitor m;

	// � ���� �ϰ� �ʹٸ�

	// #1. �� ���� ���� �ϰų�
	m.set_brightness(90);

	// #2. �� ���� �ϴ� �Լ��� ȣ���ϸ� �˴ϴ�.
	set_monitor_for_video(m);
	m.info();
}