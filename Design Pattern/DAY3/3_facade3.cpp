#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;


class NetworkInit
{
public:
	NetworkInit()
	{
		// 1. 네트워크 라이브러리 초기화
		WSADATA w;
		WSAStartup(0x202, &w);
	}
	~NetworkInit()
	{
		// 6. socket 라이브러리 cleanup
		WSACleanup();
	}
};

class IPAddress
{
	SOCKADDR_IN addr;
public:
	IPAddress(const char* ip, short port)
	{
		addr.sin_family = AF_INET;
		addr.sin_port = htons(port);
		addr.sin_addr.s_addr = inet_addr(ip);
	}
	SOCKADDR* getRawAddress()
	{
		return (SOCKADDR*)&addr;
	}
};

class Socket
{
	int sock;
public:
	Socket(int type) { sock = socket(PF_INET, type, 0); }

	void Bind(IPAddress* ip)
	{
		::bind(sock, ip->getRawAddress(), sizeof(SOCKADDR_IN));
	}
	void Listen() { ::listen(sock, 5); }

	void Accept()
	{
		struct sockaddr_in addr2 = { 0 };
		int sz = sizeof(addr2);

		accept(sock, (SOCKADDR*)&addr2, &sz);
	}
};


/*
	2번에 있던 main 아래에서 sock관련 운영하는 것도 하나의 책임으로 묶는게 facade임.

	TCP Server를 만들려면
		1. 몇개의 클래스를 사용해서
		2. 일련의 절차를 수행해야함. <--- 일종의 batch file 이나 powershell script 같은걸 만드는 pattern 이라고 보면 된다.
			=> 이런 작업도 "하나의 책임(TCPServer라는 책임)" 으로 간주.

	이런 과정을 단순화 해서 "하나의 Interface(함수)로 제공" 하는 클래스를 만들자.
	=> Facade Pattern

*/

class TCPServer {
	NetworkInit init;
	//Socket sock(SOCK_STREAM) ; // 멤버 데이터에서는 () 초기화 하면 Error
	Socket sock { SOCK_STREAM }; // TCP 서버

public :
	void Start(const char* ip, short port) {
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};


int main()
{
	TCPServer server;
	server.Start("127.0.0.1", 4000);
}


/*
	c++ MFC Library
		=> Microsoft가 만든 GUI Library
		=> facade2.cpp 처럼만 되어 있음.
		=> 사용하기 어렵고 복잡하기로 악명 높음.

	C#, Python
		=> facade3.cpp 처럼 되어 있음
		=> "TCPserver", "UDPServer" 같은 facade class가 아주 잘 되어 있음.
		=> Python의 pyexcel 등...
		=> 그래서 사용하기 아주 쉬움.
*/
