#include <iostream>
#include <string>
#include <map>
#include <functional>
#include <vector>
using namespace std::placeholders;


class NotificationCenter
{
	using HANDLER = std::function<void(void*)>;

	std::map<std::string, std::vector<HANDLER>> notif_map;
public:
	void addObserver(const std::string& key, HANDLER h)
	{
		notif_map[key].push_back(h);
	}

	void postNotificationWithName(const std::string& key, void* hint)
	{
		// 이벤트가 발생했으므로 
		// 등록된 모든 함수에 통보 한다.
		for (auto f : notif_map[key]) // notif_map[key]의 결과는 vector
			f(hint);
	}
};

void foo(void* p) { std::cout << "foo : " << (int)p << std::endl; }
void goo(void* p, int a) { std::cout << "goo : " << (int)p << std::endl; }


int main()
{
	// IOS 에 있는 통보센터를 만들어 봅시다.
	NotificationCenter nc;
	nc.addObserver("LOWBATTERY", &foo);
	nc.addObserver("LOWBATTERY", std::bind(&goo,_1,11));
	nc.addObserver("DISCONNECT_WIFI", std::bind(&goo, _1, 12));


	// 배터리 모듈쪽에서 배터리가 부족해지면
	nc.postNotificationWithName("LOWBATTERY", (void*)30);
}
