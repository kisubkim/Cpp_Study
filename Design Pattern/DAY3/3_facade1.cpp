﻿
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <iostream>
#include <WinSock2.h>
#pragma comment(lib, "ws2_32.lib")
using namespace std;

/*
	C 언어로 만든 TCP server(network) 입니다.
	
		1. C 언어는 Data와 Function이 분리되어 있기 때문에
			=> Data를 따로 초기화 한 다음에 Function Arg 로 보내야 함.
		2. 생성자가 없음으로 자동 초기화가 안됨.

	그래서, C code는 복잡해 보임.
	Data 와 Fuction 을 묶는 class로 만들면 간단해 보임.
*/



int main()
{
	// 1. 네트워크 라이브러리 초기화
	WSADATA w;
	WSAStartup(0x202, &w);

	// 2. 소켓 생성
	int sock = socket(PF_INET, SOCK_STREAM, 0); // TCP 소켓

	// 3. 소켓에 주소 지정
	struct sockaddr_in addr = { 0 };
	addr.sin_family = AF_INET;
	addr.sin_port = htons(4000);
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	bind(sock, (SOCKADDR*)&addr, sizeof(addr));

	// 4. 소켓을 대기 상태로변경
	listen(sock, 5);

	// 5. 클라이언트가 접속할때 까지 대기
	struct sockaddr_in addr2 = { 0 };
	int sz = sizeof(addr2);

	accept(sock, (SOCKADDR*)&addr2, &sz);

	// 6. socket 라이브러리 cleanup
	WSACleanup();
}
