// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

/*
	remoteproxy1.cpp 처럼 만들면...
		1. 모든 client 제작자가 IPC 기술이 필요함.
		2. 서버의 장애 처리를 모든 Client가 직접해야 함.
		3. 덧셈은 1, 뺄셈은 2 같은 명령 코드를 외우고 있어야 함.
*/

// Server를 대신하는 대행자(Proxy)를 만들어서 사용.

class Calc {
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }
	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

int main()
{
	/*
		이제 Client 제작자는 서버를 대신하는 클래스인 "Calc" 사용
			1. Client 제작자는 IPC 기술을 몰라도 됨.
			2. 서버의 장애 처리도 Proxy 가 하면 됨.
			3. 자주 사용되는 요청의 결과를 "Cache" 할 수도 있음.
			4. 1, 2 라는 명령코드 대신, "Add", "Sub" 라는 함수를 사용할 수 있음.

		RemoteProxy : 원격지 서버를 대신하는 Class !!
	*/
	Calc* calc = new Calc;
	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
}

/*
	
*/



