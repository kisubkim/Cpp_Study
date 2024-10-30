#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"


// ICalc.h ����� �Ʒ� interface �߰�

class Calc : public ICalc {
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }
	int Add(int a, int b) override { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) override { return ec_send_server(server, 2, a, b); }
};

/*
	dll �� �����ٰ� ���� ������� ���ο��� ���Ǵ� class �̸��� �˸� �ȵ�.
	��, new �ؼ� �Ҵ��ϴ� ������ dll ���ο� �־����.

	DLL �ȿ� �ִ� Proxy class name�� Client �����ڰ� �� �� ����, �� �ʿ䵵 ����, ����ص� �ȵ�.(���� ����)
	DLL ���ο� ��ӵ� �Լ��� �����, �� �ȿ��� ��ü�� �����ؾ���.
*/

extern "C" __declspec(dllexport)		// DLL �ȿ� �Լ� ���� �� �ʿ�.
ICalc* create() {
	return new Calc;
}


/*
	���ο� Procy DLL�� ���� ���� ��Ģ("create" �Լ��� �־�� �Ѵٴ�)�� ���Ѿ� ��. 

	DLL �� ����� ����. (�ڡ��߿�ڡ�)
	C++ Compiler
		Llinux �� : g++
		Windows �� Visual Studio Compiler : cl.exe
			Windows ���� > �˻����� developer command �˻��ؼ� ����
			���� �ҽ��� �ִ� ������ �̵�.
			cl CalcProcy.cpp /LD => LD�� DLL�� �����϶�� option��.
*/

/*
	�ٸ� �� ����..�̰� dll ���������ؼ��� �� ����ϵ��� ����. �ᱹ binary �� ������ �� ������ �����ϴ�
	getInstance() �̰Ű� create() �̰� �־�� �Ѵٴ� �Ŷ� ������ �κ���.

	���������� ���߿� cfg ����ؼ� dll ���ο��� class ���� �Ÿ� ������ ���� ����.

	�� ��Ģ�� �� ����ϸ� header �����ϰ� �ؼ� engine ����� ������ build �ٽ� �� �ʿ� ����.
*/