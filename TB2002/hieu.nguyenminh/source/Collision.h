#pragma once

using namespace stdio_fw;

enum Collision
{
	COLLISION_LEFT = 0,
	COLLISION_RIGHT,
	COLLISION_TOP,
	COLLISION_BOTTOM
};


bool isCollided(Rect _rect1, Rect _rect2);