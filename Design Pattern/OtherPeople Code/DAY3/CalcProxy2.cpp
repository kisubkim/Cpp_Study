// CalcProxy2.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
#include <atomic>

class Calc : public ICalc
{
	int server;
	//	int refcnt = 0; // �̷��� �ϸ� ��Ƽ ������ ȯ�濡�� ++ ������ �������� �ʽ��ϴ�.

	std::atomic<int> refcnt = 0; // ++refcnt �� ��Ƽ�����忡 ����
public:

	void AddRef() { ++refcnt; }
	void Release() { if (--refcnt == 0) delete this; }

	~Calc() { std::cout << "~Calc\n"; }


	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

extern "C" __declspec(dllexport)
ICalc* getInstance()
{
	return new Calc;
}

