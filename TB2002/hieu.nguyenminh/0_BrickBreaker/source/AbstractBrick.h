#pragma once
#include "MoveableObject.h"


class AbstractBrick :
	public MoveableObject
{
public:
	AbstractBrick();
	virtual ~AbstractBrick();
	AbstractBrick(Vec2 _Position);
};

