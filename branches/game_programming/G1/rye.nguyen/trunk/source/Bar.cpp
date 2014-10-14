#include "stdafx.h"

#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "config.h"

#include "Bar.h"

Bar::Bar()
{

}

Bar::~Bar()
{

}

void Bar::Init()
{

}

void Bar::Init(char* path, int veloc)
{
	m_image = new Image(path);
	m_image->loadImage();
	m_image->scale(0.5);

	m_object.x = 300;
	m_object.y = 500;
	m_object.width = 200;
	m_object.height = 30;

	m_default_veloc = veloc;
	m_velocity = m_default_veloc;

	m_key_press = KeyCode::KEY_UNKNOWN;
}

void Bar::Release()
{
	m_image->unloadImage();
	SAFE_DEL(m_image);
}

void Bar::Update()
{
	if(m_key_press == KeyCode::KEY_LEFT && m_object.x > 0)
		m_object.x -= m_velocity;
	else if(m_key_press == KeyCode::KEY_RIGHT && m_object.x + m_object.width < SCREEN_WIDTH)
		m_object.x += m_velocity;

	if(m_object.x < 0)
		m_object.x = 0;
	else if(m_object.x + m_object.width > SCREEN_WIDTH)
		m_object.x = SCREEN_WIDTH - m_object.width;
}

void Bar::Render(Graphics* g)
{
	g->drawImage(m_image, m_object.x, m_object.y);
}

void Bar::KeyPress(KeyCode key)
{
	m_key_press = key;
}

int Bar::GetVelocity()
{
	return m_velocity;
}

Rect Bar::GetRect()
{
	return m_object;
}

void Bar::Reset()
{
	m_object.x = 300;
	m_object.y = 500;

	m_velocity = m_default_veloc;
}