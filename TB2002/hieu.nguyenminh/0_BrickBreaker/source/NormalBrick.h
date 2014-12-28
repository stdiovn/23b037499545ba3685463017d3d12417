#pragma once

#include "AbstractBrick.h"


class NormalBrick :
	public AbstractBrick
{
public:
	NormalBrick();
	NormalBrick(Vec2 _Position);
	virtual ~NormalBrick();
	virtual void update(float deltaTime) override;
};

