// 32bit ȯ�濡�� ������ �ؾ� �մϴ�. 
// => "x64" �� �ƴ� "x86"

#define USING_GUI
#include "cppmaster.h"

/*
	Proxy ������ : Server ������.
	Proxy ����� : Client ������.


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
	// �Ʒ� ó�� ����ϸ� "���� ����"�� ��.  --> Proxy �� Update�Ǹ� code �����ؾ���.
	// �׷��� ���� ����(interface)�� ����ؾ���.
	//Calc* calc = new Calc;
	ICalc *calc = new Calc;		// �̷��� ����ϸ� ������ ���� ������.
								// Proxy�� �ҽ��� �����ϸ� �ȵ�.
								// ���� ���(dll, so) �� ���� �Ǿ�� ��.
								// => ���� �ܰ迡�� �ذ�.

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
}
