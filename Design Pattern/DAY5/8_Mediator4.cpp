#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;

/*
	중재자 패턴을 흔히...M:N 을 1:N 으로 만들어 주는 패턴이라고 함.
	(당연히 1은 중재자)
*/

class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;
	std::map<std::string, std::vector<HANDLER>> notif_map;
public:
	void addObserver(const std::string& key, HANDLER h) {
		notif_map[key].push_back(h);
	}

	void postNotificationWithName(const std::string& key, void* hint) {
		for (auto f : notif_map[key]) {
			f(hint);
		}
	}

};

void foo(void* p)		 { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) {
	std::cout << "goo : " << (int)p << std::endl;

	if (a == 11)
		std::cout << "배터리 부족" << std::endl;
	else if (a == 12)
		std::cout << "와이파이 불량" << std::endl;
}


int main()
{
	// IOS Library에 있는 통보 센터.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 11));
	nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 12));

	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}




