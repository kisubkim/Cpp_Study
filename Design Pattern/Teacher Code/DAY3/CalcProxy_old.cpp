// CalcProxy.cpp
#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); ; }
};

// DLL �ȿ� �ִ� Proxy Ŭ���� �̸���
// Ŭ���̾�Ʈ �����ڰ� �˼� ����, �� �ʿ䵵 ����, ����ص� �ȵ˴ϴ�.(���Ѱ���)
// DLL ���ο� ��ӵ� �Լ��� �����, �� �ȿ��� ��ü�� �����ؾ� �մϴ�.

extern "C" __declspec(dllexport)  // DLL �ȿ� �Լ� ���鶧 �ʿ�
ICalc* create()
{
	return new Calc;
}

// ���ο� Proxy DLL �� ���鶧�� ��Ģ("create" �Լ��� �־�� �Ѵٴ�)
// �� ���Ѿ� �մϴ�.

// C++ �����Ϸ�
// linux �� : g++
// windows �� visual studio �� ���� �����Ϸ� : cl.exe

// ������ ���۹�ư
// => �˻����� "developer command ...."

// => ���� �ҽ��� �ִ� ������ �̵�
// cd \     => C:\ ���̵�
// cd ����

// cl CalcProxy.cpp /LD     => /LD �� DLL �� �����϶�� �ɼ��Դϴ�.