#include "MyClient.h"

int main()
{
	LoopBuffer buff;

	char a[] = "123456";
	char c[] = "78";
	char b[4];

 	buff.add(a, strlen(a));
	int result = buff.read(b,1);
	buff.showValues(b, result);
	buff.add(c, strlen(c));


	result = buff.read(b, sizeof(b));
	buff.add("9", 1);
	buff.showValues(b, result);
	//std::cout << result << std::endl;

	result = buff.read(b, sizeof(b));
	buff.showValues(b, result);
	//std::cout << result << std::endl;

	result = buff.read(b, sizeof(b));
	buff.showValues(b, result);
	//std::cout << result << std::endl;

	return 0;
}