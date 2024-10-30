// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

/*
	Proxy 제작자 : Server 제작자.
	Proxy 사용자 : Client 제작자.


*/

struct ICalc {
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc {
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }
	int Add(int a, int b) override { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) override { return ec_send_server(server, 2, a, b); }
};

int main()
{
	// 아래 처럼 사용하면 "강한 결합"이 됨.  --> Proxy 가 Update되면 code 변경해야함.
	// 그래서 약한 결합(interface)로 사용해야함.
	//Calc* calc = new Calc;
	ICalc *calc = new Calc;		// 이렇게 사용하면 여전히 강한 결합임.
								// Proxy를 소스로 배포하면 안됨.
								// 동적 모듈(dll, so) 로 배포 되어야 함.
								// => 다음 단계에서 해결.

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
}
