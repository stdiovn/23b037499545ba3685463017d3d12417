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


CollisionDirection getCollisionDirection(Rect _rect1, Rect _rect2)
{
	float collison_t = _rect1.y + _rect1.height - _rect2.y;
	float collison_b = _rect2.y + _rect2.height - _rect1.y;
	float collison_l = _rect1.x + _rect1.width - _rect2.x;
	float collison_r = _rect2.x + _rect2.width - _rect1.x;

	if (isCollided(_rect1, _rect2))
	{
		if ((collison_t < collison_l) && (collison_t < collison_r) && (collison_t < collison_b))
		{
			return COLLISION_TOP;
		}
		if ((collison_b < collison_t) && (collison_b < collison_l) && (collison_b < collison_r))
		{
			return COLLISION_BOTTOM;
		}
		if ((collison_l < collison_t) && (collison_l < collison_r) && (collison_l < collison_b))
		{
			return COLLISION_LEFT;
		}
		if ((collison_r < collison_t) && (collison_r < collison_l) && (collison_r < collison_b))
		{
			return COLLISION_RIGHT;
		}
	}

	return COLLISION_NONE;
}