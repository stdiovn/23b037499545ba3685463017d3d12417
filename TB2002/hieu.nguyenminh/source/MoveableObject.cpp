#include "stdafx.h"
#include "MoveableObject.h"


MoveableObject::MoveableObject()
{
}


MoveableObject::~MoveableObject()
{
}


void MoveableObject::Dead()
{
	_isDead = true;
}


void MoveableObject::Update()
{
	if (!_isDead)
	{
		mPosition.x += _vx;
		mPosition.y += _vy;
	}
}


void MoveableObject::Render(Graphics *g)
{
	if (!_isDead)
	{
		g->drawImage(*mImage, mPosition.x, mPosition.y);
	}
}


Rect MoveableObject::getBound()
{
	Rect _rect;
	_rect.x = mPosition.x;
	_rect.y = mPosition.y;
	_rect.width = (*mImage)->getWidth();
	_rect.height = (*mImage)->getHeight();

	return _rect;
}