#pragma once
#include <iostream>
#include <string>
#include <WS2tcpip.h>
#pragma comment(lib, "ws2_32.lib")

#pragma warning(disable: 4996)

class MyClient
{
public:

	MyClient();
	static int32_t readData(char* inBuff, uint16_t lenMax);
	int32_t sendData(char* ourBuff, uint16_t len);	
	bool Connect(const char* ip, int port);
	static void msgIn(char* inBuff, int msgSize);
	void checkConnection(const char* ip, int port);
	~MyClient();

private:

	static char dataBuff[2000];
	static SOCKET Connection;
	static bool closeSocket;
	SOCKADDR_IN addr;
	WSAData wsaData;
	WORD DLLVersion;
	int sizeofaddr;
};

