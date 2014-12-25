#pragma once

#include "MoveableObject.h"


class Bar :
	public MoveableObject
{
public:
	Bar();
	virtual ~Bar();
	Bar(Vec2 _Position, Vec2 _Velocity);
	virtual void update(float deltaTime) override;
	void moveLeft(float deltaTime);
	void moveRight(float deltaTime);
};

