#include "stdafx.h"
#include "Ball.h"
#include "Resources.h"
#include "GameDefine.h"


Ball::Ball()
{
	m_Position.x = 0;
	m_Position.y = 0;
	m_isDead = false;
	m_vx = 5;
	m_vy = 0;
	m_Image = &_image_Ball;
}


Ball::~Ball()
{
}


Ball::Ball(float x, float y)
{
	m_Position.x = x;
	m_Position.y = y;
	m_isDead = false;
	m_vx = 5;
	m_vy = 0;
	m_Image = &_image_Ball;
}


