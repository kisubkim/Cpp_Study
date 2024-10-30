#define USING_GUI
#include "cppmaster.h"

// Proxy ������ : ����������
// Proxy ����� : Ŭ���̾�Ʈ������

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
	int Sub(int a, int b) { return ec_send_server(server, 2, a, b); ; }
};

int main()
{
	// �Ʒ�  ó�� ����ϸ� "���Ѱ���" �� �˴ϴ�.
	// ���ο� Proxy �� �����Ǹ� �Ʒ� �ڵ�� �����Ǿ�� �մϴ�.
	// Calc* calc = new Calc;

	// ���Ѱ���(�������̽�)�� ����ؾ� �մϴ�.
	ICalc* calc = new ? ; // ? �� ��� �ؾ� �ұ�� ?
						  // Proxy �� �ҽ��� �����ϸ� �ȵ˴ϴ�.
						  // ���� ���(dll, so) �� ���� �Ǿ�� �մϴ�.
						  // => ���� �ܰ迡�� �ذ�


	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;

}





