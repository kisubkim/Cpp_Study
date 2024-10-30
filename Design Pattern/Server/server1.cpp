// 32bit ȯ�濡�� ������ �ؾ� �մϴ�. 
// => "x64" �� �ƴ� "x86"
// 
// Server1.cpp
#define USING_GUI
#include "cppmaster.h" 

class Server
{
public:
	int Add(int a, int b) { return a + b; }
	int Sub(int a, int b) { return a - b; }
};
Server server;

/// <summary>
///  Client �� ���� (Message�� ������ Server�� ������) �ϸ� Logging�� �����,
/// ���� ���� Message�� ����Ͽ� ����� ������.
/// </summary>
/// <param name="code"> ����ϰ��� �ϴ� type�� ����. Add, Sub</param>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int handler(int code, int a, int b)
{
	printf("�޼��� ���� : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b);
	}
	return 0;
}
int main()
{
	// IPC ������ ����
	ec_start_server("Calc" /* Server Name */, &handler /* Client ���� �� �� �Լ��� ȣ���.*/);
													   // ��, Client�� Server���� int 3���� ������.
}




