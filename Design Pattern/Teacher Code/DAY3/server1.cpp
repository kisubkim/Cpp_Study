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

int handler(int code, int a, int b)
{
	printf("�޼��� ���� : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b);  // ���Լ� ��ȯ���� Ŭ���̾�Ʈ�� ���޵˴ϴ�.
	}
	return 0;
}
int main()
{
	// IPC ������ ����
	ec_start_server("Calc",    // ���� �̸�. 
					&handler); // Ŭ���̾�Ʈ ���ӽ� ���Լ��� ȣ��˴ϴ�.
							   // Ŭ���̾�Ʈ�� �������� int �� 3���� ����
							   // �ϰ� �˴ϴ�.
}




