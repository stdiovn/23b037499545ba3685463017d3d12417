#ifndef __SUPPORT_H__
#define __SUPPORT_H__

#include <string.h>

struct Vector2D
{
	int		x;
	int		y;
};

struct Rect
{
	int		x;
	int		y;
	int		width;
	int		height;
};


int			ConvertToNumber(char* str);
char*		ConvertToString(int num);

#endif