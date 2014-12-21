#include "stdafx.h"
#include "Ball.h"
#include "Resources.h"

Ball::Ball()
{
	mPosition.x = 0;
	mPosition.y = 0;
	_isDead = false;
	_vx = 5;
	_vy = 0;
	mImage = &_image_Ball;
}


Ball::~Ball()
{
}


Ball::Ball(float x, float y)
{
	mPosition.x = x;
	mPosition.y = y;
	_isDead = false;
	_vx = 5;
	_vy = 0;
	mImage = &_image_Ball;
}


