﻿#include "pch.h"
#pragma comment(lib, "ws2_32")
#include <winsock2.h>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>

const char* SERVERIP = "127.0.0.1";
const int SERVERPORT = 9000;
const int BUFSIZE = 5;

// 수신 함수
int recvn(SOCKET s, char *buf, int len, int flags)
{
	int received;
	char *ptr = buf;
	int left = len;

	while (left > 0) {
		received = recv(s, ptr, left, flags);
		if (received == SOCKET_ERROR)
			return SOCKET_ERROR;
		else if (received == 0)
			break;
		left -= received;
		ptr += received;
	}

	return (len - left);
}

int main()
{
	int retval;

	// 윈속 초기화
	WSADATA wsa;
	//std::cout << WSAStartup(MAKEWORD(2, 2), &wsa) << std::endl;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) != 0)
	{
		return 1;
	}

	// socket()
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0);
	//SOCKET sock = socket(AF_INET, SOCK_RAW, 0);
	//sock = INVALID_SOCKET;
	if (sock == INVALID_SOCKET)
	{
		printf("%d\n", GetLastError());		//dddddddddddddddd
		printf("socket()");
	}

	// connect()
	SOCKADDR_IN serveraddr;
	ZeroMemory(&serveraddr, sizeof(serveraddr));
	serveraddr.sin_family = AF_INET;
	serveraddr.sin_addr.s_addr = inet_addr(SERVERIP);
	serveraddr.sin_port = htons(SERVERPORT);
	retval = connect(sock, (SOCKADDR *)&serveraddr, sizeof(serveraddr));
	if (retval == SOCKET_ERROR)
	{
		printf("connect()");
	}

	// 데이터 통신에 사용할 변수
	char buf[BUFSIZE + 1];
	int len;

	// 서버와 데이터 통신
	while (true)
	{
		// 데이터 입력
		printf("\n[보낼 데이터] ");
		if (fgets(buf, BUFSIZE + 1, stdin) == NULL)
		{
			break;
		}

		// '\n' 문자 제거
		len = strlen(buf);
		if (buf[len - 1] == '\n')
		{
			buf[len - 1] = '\0';
		}

		if (strlen(buf) == 0)
		{
			break;
		}

		// 데이터 보내기
		retval = send(sock, buf, strlen(buf), 0);
		if (retval == SOCKET_ERROR)
		{
			printf("send()");
			break;
		}
		printf("[TCP 클라이언트] %d바이트를 보냈습니다.\n", retval);

		// 데이터 받기
		retval = recv(sock, buf, retval, 0);
		if (retval == SOCKET_ERROR)
		{
			printf("recv()");
			break;
		}
		else if (retval == 0)
		{
			break;
		}

		// 받은 데이터 출력
		buf[retval] = '\0';
		printf("[TCP 클라이언트] %d바이트를 받았습니다.\n", retval);
		printf("[받은 데이터] %s\n", buf);
	}

	// closesocket()
	closesocket(sock);

	// 윈속 종료
	WSACleanup();
	return 0;
}