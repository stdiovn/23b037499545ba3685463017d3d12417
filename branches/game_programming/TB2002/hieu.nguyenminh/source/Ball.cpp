#include "stdafx.h"
#include "Ball.h"
#include "Resources.h"
#include "GameDefine.h"
#include "Collision.h"

Ball::Ball()
{
	m_ID = ID_BALL;
	m_Image = &_image_Ball;
}


Ball::~Ball()
{
}


Ball::Ball(Vec2 _Position, Vec2 _Velocity)
	: MoveableObject(_Position, _Velocity)
{
	m_ID = ID_BALL;
	m_Image = &_image_Ball;
}


void Ball::fixPosition()
{
	if (m_Position.x <= 0)
	{
		m_Position.x = 0;
		m_Velocity.x = -m_Velocity.x;
	}

	if (m_Position.y <= 0)
	{
		m_Position.y = 0;
		m_Velocity.y = -m_Velocity.y;
	}

	if (m_Position.x + (*m_Image)->getWidth() >= 800)
	{
		m_Position.x = 800 - (*m_Image)->getWidth();
		m_Velocity.x = -m_Velocity.x;
	}

	if (m_Position.y + (*m_Image)->getHeight() >= 600)
	{
		m_Position.y = 600 - (*m_Image)->getHeight();
		m_Velocity.y = -m_Velocity.y;
	}
}


void Ball::CollisionBehavior(MoveableObject* _Collided_Object)
{
	CollisionDirection _direction = getCollisionDirection(this->getBound(), _Collided_Object->getBound());

	if ((_Collided_Object->getID() == ID_BAR) || ((_Collided_Object->getID() > ID_BRICK_REGION_BEGIN) && (_Collided_Object->getID() < ID_BRICK_REGION_END)))
	{
		if ((_direction == COLLISION_LEFT))
		{
			m_Velocity.x = -m_Velocity.x;
			m_Position.x = _Collided_Object->getPositionLeftTop().x - getBound().width;
		}

		if ((_direction == COLLISION_RIGHT))
		{
			m_Velocity.x = -m_Velocity.x;
			m_Position.x = _Collided_Object->getPositionRightBottom().x;
		}

		if ((_direction == COLLISION_TOP))
		{
			m_Velocity.y = -m_Velocity.y;
			m_Position.y = _Collided_Object->getPositionLeftTop().y - getBound().height;
		}
		if ((_direction == COLLISION_BOTTOM))
		{
			m_Velocity.y = -m_Velocity.y;
			m_Position.y = _Collided_Object->getPositionRightBottom().y;
		}

		if ((_Collided_Object->getID() > ID_BRICK_REGION_BEGIN) && (_Collided_Object->getID() < ID_BRICK_REGION_END))
		{
			_Collided_Object->setDead();
		}
	}
	
}

void Ball::update(float deltaTime)
{
	m_Position += Vec2(m_Velocity.x * deltaTime, m_Velocity.y * deltaTime);
	fixPosition();
}