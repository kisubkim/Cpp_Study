#include "monitor.h"

void set_monitor_for_video(Monitor& m) {
	m.set_brightness(90);
	m.set_resolution(1920);
}

int main()
{
	Monitor m;

	// 어떤 일을 하고 싶다면

	// #1. 그 일을 직접 하거나
	m.set_brightness(90);

	// #2. 그 일을 하는 함수를 호출하면 됩니다.
	set_monitor_for_video(m);
	m.info();
}