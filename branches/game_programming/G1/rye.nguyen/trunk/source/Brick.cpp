#include "stdafx.h"
#include "STDIO_FW\Video\Graphics.h"
#include "config.h"

#include "Brick.h"

Brick::Brick()
{

}

Brick::~Brick()
{

}

void Brick::Init()
{

}

void Brick::Init(int position_x, int position_y, int width, int height)
{
	m_object.x = position_x;
	m_object.y = position_y;
	m_object.width = width;
	m_object.height = height;

	m_color = RANDOM_COLOR;

	m_is_alive = true;
}

void Brick::Release()
{

}

void Brick::Update()
{

}

void Brick::Render(Graphics* g)
{
	g->setColor(m_color);

	g->drawRect(m_object.x, m_object.y, m_object.width, m_object.height);
	g->fillRect(m_object.x, m_object.y, m_object.width, m_object.height);
}

Rect Brick::GetRect()
{
	return m_object;
}

bool Brick::IsAlive()
{
	return m_is_alive;
}

void Brick::Activate()
{
	m_is_alive = true;
}

void Brick::DeActivate()
{
	m_is_alive = false;
}