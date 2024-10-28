#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;
	std::map<std::string, std::vector<HANDLER>> notif_map;	// void return을 가지고, 인자로 void*를 가지는 std::function
public:
	void addObserver(const std::string& key, HANDLER h){
		notif_map[key].push_back(h);
	}

	void postNotificationWithName(const std::string& key, void* hint){
		for(auto& f : notif_map[key]){
			f(hint);		// 현재 f는 std::function
		}
	}
};

void foo(void* p)        { std::cout << "foo : " << (long long)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (long long)p << std::endl; }


int main()
{
	// IOS 의 cocoa touch library 에 있는 class를 c++로 만든 것.
	NotificationCenter nc;

	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo, _1, 1));
	nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 2));

	// 배터리 모듈쪽에서 배터리가 부족해지면 - OS 내부에서 이렇게 하고 있다고 가정.
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
	nc.postNotificationWithName("DISCONNECT_WIFI", (void*)0);
}




