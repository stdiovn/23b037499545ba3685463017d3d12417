#include "stdafx.h"
#include "Collision.h"

bool isCollided(Rect _rect1, Rect _rect2)
{
	if ((_rect1.x + _rect1.width < _rect2.x) ||
		(_rect2.x + _rect2.width < _rect1.x) ||
		(_rect1.y + _rect1.height < _rect2.y) ||
		(_rect2.y + _rect2.height < _rect1.y))
	{
		return false;
	}

	return true;
}