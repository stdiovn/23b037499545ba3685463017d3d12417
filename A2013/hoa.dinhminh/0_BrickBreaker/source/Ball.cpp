#include "stdafx.h"

#include "Ball.h"


CBall::CBall()
{

}

CBall::CBall(int _x, int _y)
{
	this->x = _x;
	this->y = _y;
}

CBall::CBall(const CBall& ball)
{
	this->x = ball.x;
	this->y = ball.y;
}
