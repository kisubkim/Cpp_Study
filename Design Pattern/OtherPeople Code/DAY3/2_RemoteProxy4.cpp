// Client �����ڴ� ���������ڿ��� 2���� ������ �޾ƾ� �մϴ�.

// ICalc.h       : �������̽��� �ִ� ���
// CalcProxy.dll : Proxy ���� �ڵ尡 �ִ� �������

#include "ICalc.h"

int main()
{
	ICalc* calc = load_proxy();

	int n1 = calc->Add(10, 20);
	int n2 = calc->Sub(10, 20);

	// dll delete���� header�� �����ؾ���.
	
	std::cout << n1 << ", " << n2 << std::endl;

}


