#pragma once

#include "MoveableObject.h"


class Ball :
	public MoveableObject
{
public:
	Ball();
	virtual ~Ball();
	Ball(Vec2 _Position, Vec2 _Velocity);
	void CollisionBehavior(MoveableObject* _Collided_Object);
	void fixPosition();
	virtual void update(float deltaTime) override;
};

