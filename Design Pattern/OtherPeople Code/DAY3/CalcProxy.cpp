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

extern "C" __declspec(dllexport) //windows ���� DLL���鋞 �Լ� �տ� �ٿ��� �Ѵ�. ����������� ��� ��.
ICalc* getInstance() {
	return new Calc;
}

// windows c++ �����Ϸ� �̸� - cl.exe