#include "stdafx.h"

#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
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
	
	m_image = new Image("image\\brick.png");
	m_image->loadImage();
}

void Brick::Release()
{
	m_image->unloadImage();
	delete m_image;
}

void Brick::Update()
{

}

void Brick::Render(Graphics* g)
{
	g->drawImage(m_image, m_object.x, m_object.y);
}

Rect Brick::GetRect()
{
	return m_object;
}

bool Brick::IsActive()
{
	return m_is_active;
}

void Brick::Activate()
{
	m_is_active = true;
}

void Brick::DeActivate()
{
	m_is_active = false;
}