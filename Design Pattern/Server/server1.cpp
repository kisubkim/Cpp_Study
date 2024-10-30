// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"
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
///  Client 가 접속 (Message를 보내서 Server가 받으면) 하면 Logging을 남기고,
/// 전달 받은 Message를 사용하여 계산을 진행함.
/// </summary>
/// <param name="code"> 계산하고자 하는 type을 정함. Add, Sub</param>
/// <param name="a"></param>
/// <param name="b"></param>
/// <returns></returns>
int handler(int code, int a, int b)
{
	printf("메세지 도착 : %d, %d, %d\n", code, a, b);
	switch (code)
	{
	case 1: return server.Add(a, b);
	case 2: return server.Sub(a, b);
	}
	return 0;
}
int main()
{
	// IPC 서버로 시작
	ec_start_server("Calc" /* Server Name */, &handler /* Client 접속 시 이 함수가 호출됨.*/);
													   // 단, Client는 Server에게 int 3개를 전달함.
}




