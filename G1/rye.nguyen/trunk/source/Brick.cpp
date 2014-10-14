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

void Brick::Init(char* path1, char* path2, int position_x, int position_y, int width, int height)
{
	m_image1 = new Image(path1);
	m_image1->loadImage();
	m_image1->scale(0.5);

	m_image2 = new Image(path2);
	m_image2->loadImage();
	m_image2->scale(0.5);

	m_object.x = position_x;
	m_object.y = position_y;
	m_object.width = width;
	m_object.height = height;

	m_lives = 1;
}

void Brick::Release()
{
	m_image1->unloadImage();
	SAFE_DEL(m_image1);

	m_image2->unloadImage();
	SAFE_DEL(m_image2);

	m_image = NULL;
}

void Brick::Update()
{
	if(m_lives == 2)
		m_image = m_image2;
	else
		m_image = m_image1;
}

void Brick::Render(Graphics* g)
{
	g->drawImage(m_image, m_object.x, m_object.y);
}

int Brick::GetLives()
{
	return m_lives;
}

void Brick::SetLive(int value)
{
	m_lives = value;
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