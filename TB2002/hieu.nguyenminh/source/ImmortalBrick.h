#pragma once
#include "AbstractBrick.h"


class ImmortalBrick :
	public AbstractBrick
{
public:
	ImmortalBrick();
	virtual ~ImmortalBrick();
	virtual void update(float deltaTime) override;
};

