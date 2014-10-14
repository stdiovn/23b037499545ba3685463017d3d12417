#include "support.h"

char* ConvertToString(int num)
{
	int count = 0;
	int temp = num;

	while(temp != 0)
	{
		temp /= 10;
		count++;
	}

	char* str = new char[count];
	temp = num;

	for(int i = 0; i < count; i++)
	{
		str[count - i - 1] = temp % 10;
		temp /= 10;
	}

	return str;
}