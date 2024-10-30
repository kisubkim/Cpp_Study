// 32bit ȯ�濡�� ������ �ؾ� �մϴ�. 
// => "x64" �� �ƴ� "x86"

#define USING_GUI
#include "cppmaster.h"
#include "ICalc.h"
/*
	Client �����ڴ� "Server ������" ���� 2���� ������ �޾ƿ;� ��.

	ICalc.h : Interface�� �ִ� Header
	CalcProcy.dll : Proxy�� ��� ���� ��� (Class�� �̸� ������ �� ��)
*/

/*
	Proxy Update �� ��Ģ
		1. DLL �� �̸��� �����ϸ� �ȵ�. ("CalcProxy.dll" ����)
		2. DLL �ȿ� "create" �� �־����.
*/

//


int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(1, 2);
	int n2 = calc->Sub(1, 2);

	std::cout << n1 << std::endl;
	std::cout << n2 << std::endl;
}
