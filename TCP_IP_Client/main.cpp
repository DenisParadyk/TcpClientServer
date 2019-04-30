#include "MyClient.h"

int main()
{
	LoopBuffer buff;

	int a[] = {1, 2, 3, 4, 5 ,6};
	int c[] = {7, 8};
	int b[8];

 	buff.add(a, 6);
	buff.add(c, 2);

 	int result = buff.read(b, 8);

	buff.showValues(b, 8);

	std::cout << "\tButes read:" << result << std::endl;

	/*
	char a[] = "123456";
	char b[] = "78";
	char c[8];
	
	buff.add(a, strlen(a));
	buff.add(b, strlen(a));

	int result = buff.read(b, 5);

	buff.showValues(b, 5);

	std::cout << "\tButes read:" << result << std::endl;
	*/

	/*
	float a[] = { 1, 2, 3, 4, 5 ,6 };
	float b[] = { 7, 8 };
	float c[8];

	buff.add(a, 6);
	buff.add(b, 2);

	int result = buff.read(b, 8);

	buff.showValues(b, 8);

	std::cout << "\tButes read:" << result << std::endl;
	*/

	return 0;
}