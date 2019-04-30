#include "LoopBuffer.h"

LoopBuffer::LoopBuffer()
{
	theLastAdress = 0;
	counterButes = 0;

	for (int i = 0; i < sizeof(MyBuff); i++)
	{
		MyBuff[i] = emptyBute;
	}
}

bool LoopBuffer::checkData(int dataSize, int userBuffSize, char* data, char* userBuff)
{
	if (dataSize == userBuffSize)
	{
		for (int i = 0; i < dataSize; i++)
		{
			if (data[i] == userBuff[i]) {}

			else
			{
				return false;
			}
		}
		return true;
	}
	else 
	{
		return false;
	}
}