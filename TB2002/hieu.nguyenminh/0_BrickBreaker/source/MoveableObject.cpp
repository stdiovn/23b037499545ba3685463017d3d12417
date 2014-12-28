#include "stdafx.h"
#include "MoveableObject.h"
#include "GameDefine.h"


MoveableObject::MoveableObject()
{
	m_isDead = false;
	m_Position = Vec2(0, 0);
	m_Velocity = Vec2(0, 0);
}


MoveableObject::MoveableObject(Vec2 _Position, Vec2 _Velocity)
{
	m_isDead = false;
	m_Position = _Position;
	m_Velocity = _Velocity;
}

MoveableObject::~MoveableObject()
{
}


void MoveableObject::setDead()
{
	m_isDead = true;
}



void MoveableObject::render(Graphics *g)
{
	if (!m_isDead)
	{
		g->drawImage(*m_Image, m_Position.x, m_Position.y);
	}
}


ObjectID MoveableObject::getID()
{
	return m_ID;
}


Rect MoveableObject::getBound()
{
	Rect _rect;
	_rect.x = m_Position.x;
	_rect.y = m_Position.y;
	_rect.width = (*m_Image)->getWidth();
	_rect.height = (*m_Image)->getHeight();

	return _rect;
}


Vec2 MoveableObject::getPositionLeftTop()
{
	return Vec2(m_Position);
}


Vec2 MoveableObject::getPositionRightBottom()
{
	Vec2 _RightBottom;
	_RightBottom.x = m_Position.x + (*m_Image)->getWidth();
	_RightBottom.y = m_Position.y + (*m_Image)->getHeight();

	return _RightBottom;
}


bool MoveableObject::isDead()
{
	return m_isDead;
}