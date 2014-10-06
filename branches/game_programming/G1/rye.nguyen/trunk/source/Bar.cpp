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
	m_object.x = 300;
	m_object.y = 500;
	m_object.width = 200;
	m_object.height = 30;

	m_velocity = 5;

	m_image = new Image("image\\bar.png");
	m_image->loadImage();
	m_image->scale(0.5);

	m_key_press = KeyCode::KEY_UNKNOWN;
}

void Bar::Release()
{
	m_image->unloadImage();
	delete m_image;
}

void Bar::Update()
{
	if(m_key_press == KeyCode::KEY_LEFT && m_object.x >= 0)
		m_object.x -= m_velocity;
	else if(m_key_press == KeyCode::KEY_RIGHT && m_object.x + m_object.width <= SCREEN_WIDTH)
		m_object.x += m_velocity;
}

void Bar::Render(Graphics* g)
{
	/*g->drawRect(m_object.x, m_object.y, m_object.width, m_object.height);
	g->fillRect(m_object.x, m_object.y, m_object.width, m_object.height);*/
	g->drawImage(m_image, m_object.x, m_object.y);
}

void Bar::KeyPress(KeyCode key)
{
	m_key_press = key;
}

Rect Bar::GetRect()
{
	return m_object;
}

int Bar::GetVelocity()
{
	return m_velocity;
}