#pragma once
#include <string>
#include <iostream>
#include <WS2tcpip.h>
#include "LoopBuffer.h"
#pragma warning(disable: 4996)
#pragma comment(lib, "ws2_32.lib")

class MyClient
{
public:

	MyClient();
	static int32_t readData(char* inBuff, uint16_t lenMax);
	void checkConnection(const char* ip, int port);
	static int32_t sendData(char* ourBuff, uint16_t len);
	int32_t readDataBuff(char* inBuff, int32_t lenMax);
	bool Connect(const char* ip, int port);
	~MyClient();
private:

	static SOCKET Connection;
	static bool closeSocket;
	SOCKADDR_IN addr;
	WSAData wsaData;
	WORD DLLVersion;
	int sizeofaddr;
};

