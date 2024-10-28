#define USING_GUI
#include "cppmaster.h"

struct ICalc
{
	virtual int Add(int a, int b) = 0;
	virtual int Sub(int a, int b) = 0;
	virtual ~ICalc() {}
};

class Calc : public ICalc
{
	int server;
public:
	Calc() { server = ec_find_server("Calc"); }

	int Add(int a, int b) { return ec_send_server(server, 1, a, b); }
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); }
};

// Proxy ������ : Server �����ڰ� ���� ����
// Proxy ����� : Client �����ڰ� ���.


int main()
{
	// �Ʒ� ó�� ����� "���� ����" �Դϴ�.
	// ���ο�  Proxy �� ������ �Ʒ� �ڵ�� �����Ǿ�� �մϴ�.
	// OCP ����
	// Calc* calc = new Calc;

	// �������̽� ����� ���Ѱ������� ����ؾ� �մϴ�.
	ICalc* calc = new ? ; // ? �� ��� �ؾ� �ұ�� ??
	// proxy �� �ҽ��� ���� �ϸ� �ȵ˴ϴ�.
	// �������� �����Ǿ�� �մϴ�.(.dll, .so)
	// => �����ܰ迡��..

// �ҽ��� �����ϸ� 
// ���ο� proxy ���ö� "Ŭ���̾�Ʈ �����ڴ� �ּ��� �ٽ� ����" �ϴ� �۾��� �ϰԵ˴ϴ�.
// �̷� �۾��� ���� �ʵ��� �ؾ� �մϴ�.


	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}

