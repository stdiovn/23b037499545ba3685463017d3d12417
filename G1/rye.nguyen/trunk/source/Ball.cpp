#include "stdafx.h"

#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include "config.h"

#include "Ball.h"


Ball::Ball()
{
	
}

Ball::~Ball()
{

}

void Ball::Init()
{

}

void Ball::Init(char* path, Vector2D veloc)
{
	m_image = new Image(path);
	m_image->loadImage();
	m_image->scale(0.5);

	m_default_veloc.x = veloc.x;
	m_default_veloc.y = veloc.y;

	m_velocity.x = m_default_veloc.x;
	m_velocity.y = m_default_veloc.y;

	m_object.x = 375;
	m_object.y = 450;
	m_object.width = 50;
	m_object.height = 50;

	m_is_active = true;
}

void Ball::Release()
{
	m_image->unloadImage();
	SAFE_DEL(m_image);
}

void Ball::Update()
{
	CheckCollisionWithScreen();

	m_object.x += m_velocity.x;
	m_object.y += m_velocity.y;
}

void Ball::Render(Graphics* g)
{
	g->drawImage(m_image, m_object.x, m_object.y);
}

void Ball::CheckCollisionWithScreen()
{
	if(m_object.x <= 0)
	{
		m_object.x = 0;
		m_velocity.x = -m_velocity.x;
	}
	else if(m_object.x + m_object.width >= SCREEN_WIDTH)
	{
		m_object.x = SCREEN_WIDTH - m_object.width;
		m_velocity.x = -m_velocity.x;
	}
	
	if(m_object.y <= 0)
	{
		m_object.y = 0;
		m_velocity.y = -m_velocity.y;
	}
	else if(m_object.y + m_object.height >= SCREEN_HEIGHT)
	{
		m_object.y = SCREEN_HEIGHT - m_object.height;
		m_velocity.y = -m_velocity.y;

		//Lose a live when collides with the bottom edge
		m_is_active = false;
	}
}


//Check collides between Ball's rect and other objects' rect
//Return: true when collided and false when not collided
bool Ball::IsCollisionWithObject(Rect object, int velocity)
{
	if(m_object.x + m_object.width >= object.x && m_object.x <= object.x + object.width && m_object.y + m_object.height >= object.y && m_object.y <= object.y + object.height)
	{
		if(m_velocity.y > 0 && m_object.y + m_object.height - m_velocity.y < object.y)
		{
			m_object.y = object.y - m_object.height;
			m_velocity.y = -m_velocity.y;
		}
		else if(m_velocity.y < 0 && m_object.y - m_velocity.y > object.y + object.height)
		{
			m_object.y = object.y + object.height;
			m_velocity.y = -m_velocity.y;
		}

		if(m_velocity.x > 0 && m_object.x + m_object.width - m_velocity.x - velocity < object.x)
		{
			m_object.x = object.x - m_object.width;
			m_velocity.x = -m_velocity.x;
		}
		else if(m_velocity.x < 0 && m_object.x - m_velocity.x + velocity > object.x + object.width)
		{
			m_object.x = object.x + object.width;
			m_velocity.x = -m_velocity.x;
		}

		return true;
	}

	return false;
}

bool Ball::IsActive()
{
	return m_is_active;
}

void Ball::Reset()
{
	m_object.x = 375;
	m_object.y = 450;

	m_velocity.x = m_default_veloc.x;
	m_velocity.y = m_default_veloc.y;

	m_is_active = true;
}