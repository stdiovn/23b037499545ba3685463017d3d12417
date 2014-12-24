#include "stdafx.h"
#include "MoveableObject.h"
#include "GameDefine.h"


MoveableObject::MoveableObject()
{
}


MoveableObject::~MoveableObject()
{
}


void MoveableObject::Dead()
{
	m_isDead = true;
}


void MoveableObject::Update(float deltaTime)
{
	if (!m_isDead)
	{
		m_Position.x += m_vx;
		m_Position.y += m_vy;
	}
}


void MoveableObject::Render(Graphics *g)
{
	if (!m_isDead)
	{
		g->drawImage(*m_Image, m_Position.x, m_Position.y);
	}
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