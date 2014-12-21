#pragma once
#include "AbstractBrick.h"
class NormalBrick :
	public AbstractBrick
{
public:
	NormalBrick();
	NormalBrick(float x, float y);
	virtual ~NormalBrick();
};

