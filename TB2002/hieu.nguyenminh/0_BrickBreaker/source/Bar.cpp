#include "stdafx.h"
#include "Bar.h"
#include "Resources.h"
#include "GameDefine.h"
#include "math.h"

Bar::Bar()
{
	m_ID = ID_BAR;
	m_Image = &_image_Bar;
}


Bar::Bar(Vec2 _Position, Vec2 _Velocity) 
	: MoveableObject(_Position, _Velocity)
{
	m_ID = ID_BAR;
	m_Image = &_image_Bar;
}


Bar::~Bar()
{
}


void Bar::update(float deltaTime)
{

}


void Bar::moveLeft(float deltaTime)
{
	m_Position.x -= abs(m_Velocity.x) * deltaTime;
	if (m_Position.x < 0)
	{
		m_Position.x = 0;
	}
}


void Bar::moveRight(float deltaTime)
{
	m_Position.x += abs(m_Velocity.x) * deltaTime;
	if (m_Position.x + getBound().width> 800)
	{
		m_Position.x = 800 - getBound().width;
	}
}