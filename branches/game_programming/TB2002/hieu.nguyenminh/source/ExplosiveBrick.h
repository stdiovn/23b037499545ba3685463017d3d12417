#pragma once
#include "AbstractBrick.h"


class ExplosiveBrick :
	public AbstractBrick
{
public:
	ExplosiveBrick();
	virtual ~ExplosiveBrick();
	virtual void update(float deltaTime) override;
};

