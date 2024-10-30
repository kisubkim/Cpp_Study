// 32bit 환경에서 컴파일 해야 합니다. 
// => "x64" 가 아닌 "x86"

#define USING_GUI
#include "cppmaster.h"

int main()
{
	// 1. 서버의 핸들을 얻어 옵니다.
	int server = ec_find_server("Calc");

	std::cout << "서버 번호 : " << server << std::endl;

	// 2. 서버에 명령코드와 파라미터를 전달합니다.
	int n1 = ec_send_server(server, 1, 10, 20);		// server로 보내면 그 결과가 n1 으로 들어감.
	int n2 = ec_send_server(server, 2, 10, 20);

	std::cout << n1 << ", " << n2 << std::endl;

}

/*
	[ A ] <----> [ B ] 
	두 process 간에 통신을 하는 프로그램이 server.zip 이고 이것과 왔다갔다가하는 예제가 RemoteProxy.
	IPC (Internal Process Communication)

*/



