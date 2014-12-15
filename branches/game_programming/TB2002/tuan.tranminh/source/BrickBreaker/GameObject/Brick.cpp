#include "stdafx.h"
#include "BrickBreaker/GameObject/Brick.h"


void Brick::setBrickProperties(Vector2 position)
{
	MoveObject::setMoveObjectProperties(position, BRICK_SIZE_WIDTH, BRICK_SIZE_HEIGHT, SPEED_NO);
}
