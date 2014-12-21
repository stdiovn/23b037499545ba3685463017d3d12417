#pragma once
#include "MoveableObject.h"
class Ball :
	public MoveableObject
{
public:
	Ball();
	Ball(float x, float y);

	virtual ~Ball();
};

