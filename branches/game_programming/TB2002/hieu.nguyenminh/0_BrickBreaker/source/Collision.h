#pragma once

using namespace stdio_fw;

enum CollisionDirection
{
	COLLISION_NONE =0,
	COLLISION_LEFT,
	COLLISION_RIGHT,
	COLLISION_TOP,
	COLLISION_BOTTOM
};


bool isCollided(Rect _rect1, Rect _rect2);

CollisionDirection getCollisionDirection(Rect _rect1, Rect _rect2);