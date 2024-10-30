#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
#include <atomic>		// 멀티쓰레드 안전한 타입을 사용할 때 사용

class Calc : public ICalc {
	int server;

	//int ref = 0;		// 멀티스레드 환경에서 안전하게 +, - 안됨.
	std::atomic<int> ref = 0;		// 멀티쓰레드 안전
public:

	void AddRef() { ++ref; }
	void Release() { if (--ref == 0) delete this; }

	Calc() { server = ec_find_server("Calc"); }
	~Calc() {
		std::cout << "~Calc" << std::endl;
	}
	int Add(int a, int b) override { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) override { return ec_send_server(server, 2, a, b); }
};

extern "C" __declspec(dllexport)
ICalc* create() {
	return new Calc;
}

/*
	댕글링 포인터
		만약에 여러 변수가 한개의 객체를 포인터로 물고 있는데, 한 놈이 지워버리면 나머지는 난리남. 이런 현상에서 지워진 놈을 가리키는 포인터가 댕글링 포인터임.


*/