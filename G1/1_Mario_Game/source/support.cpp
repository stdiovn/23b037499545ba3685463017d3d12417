#include "stdafx.h"

#include <string>

#include "support.h"

bool g_isCollide(Rect st, Rect nd)
{
	return st.x + st.width >= nd.x && st.x <= nd.x + nd.width && st.y + st.height >= nd.y && st.y <= nd.y + nd.height;
}

///////////////////////////////////////////////////////
//Coder: Rye
//Purpose: Reimplement getNumber function
int g_getNumber(char* s)
{
	int result = 0;
	while(*s < '0' || *s > '9') s++;

	while(*s >= '0' && *s <= '9')
	{
		result *= 10;
		result += *s - '0';
		s++;
	}

	return result;
}