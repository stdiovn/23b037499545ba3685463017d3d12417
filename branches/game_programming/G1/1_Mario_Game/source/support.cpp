#include "stdafx.h"

#include <string>

#include "support.h"

Direction g_isCollide(Rect st, Rect nd, Vec2 stVeloc, Vec2 ndVeloc)
{
	if((st.x + st.width < nd.x && st.x + st.width - stVeloc.x < nd.x - ndVeloc.x) ||
		(st.x > nd.x + nd.width && st.x - stVeloc.x > nd.x + nd.width - ndVeloc.x) ||
		(st.y + st.height < nd.y && st.y + st.height - stVeloc.y < nd.y - ndVeloc.y) ||
		(st.y > nd.y + nd.height && st.y - stVeloc.y > nd.y + nd.height - ndVeloc.y))
		return Direction::DIR_NONE;
	else
	{
		Direction collideDirection = Direction::DIR_UNKNOWN;

		if(st.y + st.height - stVeloc.y <= nd.y - ndVeloc.y)
			collideDirection = Direction::DIR_TOP;
		else if(st.y - stVeloc.y > nd.y + nd.height - ndVeloc.y)
			collideDirection = Direction::DIR_BOTTOM;

		if(st.x + st.width - stVeloc.x < nd.x - ndVeloc.x)
		{
			if(collideDirection == Direction::DIR_TOP)
				collideDirection = Direction::DIR_TOP_LEFT;
			else if(collideDirection == Direction::DIR_BOTTOM)
				collideDirection = Direction::DIR_BOTTOM_LEFT;
			else
				collideDirection = Direction::DIR_LEFT;
		}
		else if(st.x - stVeloc.x > nd.x + nd.width - ndVeloc.x)
		{
			if(collideDirection == Direction::DIR_TOP)
				collideDirection = Direction::DIR_TOP_RIGHT;
			else if(collideDirection == Direction::DIR_BOTTOM)
				collideDirection = Direction::DIR_BOTTOM_RIGHT;
			else
				collideDirection = Direction::DIR_RIGHT;
		}

		return collideDirection;
	}
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