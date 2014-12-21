#include "stdafx.h"
#include "NormalBrick.h"
#include "Resources.h"

NormalBrick::NormalBrick()
{
	mPosition.x = 0;
	mPosition.y = 0;
	_isDead = false;
	mImage = &_image_Brick;
	_vx = 0;
	_vy = 0;
}

NormalBrick::NormalBrick(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;
	_isDead = false;
	mImage = &_image_Brick;
	_vx = 0;
	_vy = 0;
}


NormalBrick::~NormalBrick()
{
}

