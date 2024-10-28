#define USING_GUI
#include "cppmaster.h"

// 서버를 대신하는 클래스를 만들어 봅시다.
// => Remote Proxy

// remote proxy 덕분에

// 1. 클라이언트 제작자는 IPC 기술을 몰라도 됩니다.

// 2. 서버에 응답이 없으면 백업서버로 연결하는 과정을
//    proxy 가 하면 됩니다.

// 3. cache 기능도 proxy 에 추가할수 있습니다.

// 4. 1, 2 을 외우지 않아도 됩니다. Add, Sub 호출!!

class Calc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	Calc* calc = new Calc;

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}

