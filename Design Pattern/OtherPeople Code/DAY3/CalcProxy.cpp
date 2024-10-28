#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

extern "C" __declspec(dllexport) //windows 에서 DLL만들떈 함수 앞에 붙여야 한다. 리눅스등에서는 없어도 됨.
ICalc* getInstance() {
	return new Calc;
}

// windows c++ 컴파일러 이름 - cl.exe