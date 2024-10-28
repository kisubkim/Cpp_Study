#define _WINSOCK_DEPRECATED_NO_WARNINGS﻿
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


// TCP 서버를 만들려면
// => 라이브러리내의 몇개의 클래스를 가지고
// => 몇가지의 전형적인 절차를 거쳐야 합니다.
// => 이런 전형적인 절차도 "하나의 책임" 입니다.

// TCP 서버를 단순화 하는 상위 레벨의 클래스를 제공합니다

class TCPServer
{
	NetworkInit init;
	Socket sock{ SOCK_STREAM };
public:
	void Start(const char* ip, short port)
	{
		IPAddress addr(ip, port);
		sock.Bind(&addr);
		sock.Listen();
		sock.Accept();
	}
};

int main()
{
	// 이제 최종사용자 코드는 아래와 같습니다.
	// => facade 계층 때문에 코드가 아주 간단해 졌습니다.
	// => C#, Python 등이 facade 계층이 아주 잘 만들어져 있기 때문에
	//    사용하기 쉬운것 입니다.
	TCPServer server;
	server.Start("127.0.0.1", 4000); // 

}