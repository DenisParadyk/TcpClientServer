#pragma once
#include <iostream>

#define emptyBute 0

template <class T>
class LoopBuffer
{
public:

	LoopBuffer()
	{
		theLastAdress = 0;
		counterButes = 0;

		for (int i = 0; i < sizeof(MyBuff); i++)
		{
			MyBuff[i] = emptyBute;
		}
	}

	bool add(const T* data, int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (theLastAdress == sizeof(MyBuff))
			{
				theLastAdress = 0;
			}

			MyBuff[theLastAdress] = data[i];

			theLastAdress++;
			counterButes++;
		}

		if (counterButes > sizeof(MyBuff))
		{
			return false;
		}

		return true;
	}

	int32_t read(T* userBuff, int len)
	{
		int tempFrst = sizeof(MyBuff) + (theLastAdress - counterButes);
		int tempScnd = theLastAdress - counterButes;
		int bytesRead = 0;
		int readPtr = 0;

		if (tempFrst == 1000)
		{
			tempFrst++;
		}

		if (counterButes == 0)
		{
			return 0;
		}
		else
		{
			for (int i = 0; i < len; i++)
			{
				if (len > theLastAdress)
				{
					userBuff[i] = MyBuff[tempFrst];
					tempFrst++;

					if (tempFrst == sizeof(MyBuff))
					{
						tempFrst = 0;
					}
					if (MyBuff[tempFrst] != emptyBute)
					{
						bytesRead++;
					}
				}
				else if (len < theLastAdress)
				{
					userBuff[i] = MyBuff[tempScnd];
					bytesRead++;
					tempScnd++;
				}
				else if (len == theLastAdress)
				{
					userBuff[i] = MyBuff[readPtr];
					bytesRead++;
					readPtr++;
				}
				else
				{
					return false;
				}

				counterButes--;
			}
		}

		return bytesRead;
	}

	void showValues(T* data, int size)
	{
		for (int i = 0; i < size; i++)
		{
			if (data[i] == emptyBute)
			{
				continue;
			}

			std::cout << data[i] << " ";
		}
	}

private:

	T MyBuff[1000];
	int theLastAdress;
	int counterButes;

};
