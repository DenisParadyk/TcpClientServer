#include "MyClient.h"

int main()
{
	MyClient client;
	const char ip[] = "127.0.0.1";
	int port = 8888;

	client.Connect(ip, port);
	client.checkConnection(ip, port);

	char Sbuff[] = "My_Message";
	char* Rbuff = new char[256];

	int32_t SbuffSize = sizeof(Sbuff);
	int32_t RbuffSize = sizeof(Rbuff);

	while (client.Connect(ip, port))
	{
		client.readData(Rbuff, RbuffSize);
		client.sendData(Sbuff, SbuffSize);	
	}

	delete[] Rbuff;
	system("pause");

	return 0;
}