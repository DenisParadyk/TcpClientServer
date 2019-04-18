#include "MyClient.h"
#include "LoopBuffer.h"

SOCKET MyClient::Connection = NULL;
bool MyClient::closeSocket = FALSE;

MyClient::MyClient()
{
	DLLVersion = MAKEWORD(2, 1);
	if (WSAStartup(DLLVersion, &wsaData) != 0) 
	{
		printf("Error WSAStartup %d\n",
		WSAGetLastError());
	}
}

bool MyClient::Connect(const char* ip, int port)
{
	sizeofaddr = sizeof(addr);
	addr.sin_addr.s_addr = inet_addr(ip);
	addr.sin_port = htons(port);
	addr.sin_family = AF_INET;

	Connection = socket(AF_INET, SOCK_STREAM, NULL);

	if (connect(Connection, (SOCKADDR*)&addr, sizeof(addr)) != 0)
	{
		closeSocket = false;
		return closeSocket;
	}
	closeSocket = true;

	CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)readData, NULL, NULL, NULL);

	return closeSocket;
}

int32_t MyClient::readData(char* inBuff, uint16_t lenMax)
{
	int32_t lenRecive;
	LoopBuffer buff;

	while (true)
	{
		lenRecive = recv(Connection, inBuff, lenMax, NULL);

		if (lenRecive > 0)
		{
			buff.add(inBuff, lenMax);
		}
	}
	return lenRecive;
}

void MyClient::checkConnection(const char * ip, int port)
{
	Connect(ip, port) ? std::cout << "Connected" << std::endl :
		std::cout << "Error: failed connect to server" << std::endl;
}

int32_t MyClient::sendData(char * ourBuff, uint16_t len)
{
	int32_t lenSend;
	lenSend = send(Connection, ourBuff, len, NULL);

	if (ourBuff != 0)
	{
		std::cout << "Send message :" << ourBuff << std::endl;
	}

	return lenSend;
}

int32_t MyClient::readDataBuff(char *inBuff , int32_t lenMax)
{
	LoopBuffer buff;
	int32_t lenRecv;

	buff.read(inBuff, lenMax);

	return 0;
}

MyClient::~MyClient()
{
	if (!closeSocket) 
	{
		closesocket(Connection);
	}
}
