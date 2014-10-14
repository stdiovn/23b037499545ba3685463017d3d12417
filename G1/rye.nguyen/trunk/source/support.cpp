#include "support.h"

int ConvertToNumber(char* str)
{
	int sign = 1;
	if(*str == '-')
	{
		sign = -1;
		str++;
	}
	else if(*str == '+')
		str++;

	int value = 0;
	while(*str >= '0' && *str <= '9')
	{
		value *= 10;
		value += (*str - 48);
		str++;
	}

	return value * sign;
}

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