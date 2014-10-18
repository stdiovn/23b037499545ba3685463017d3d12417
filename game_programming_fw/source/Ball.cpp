#include "stdafx.h"
#include "Ball.h"
#define SPEED 3;

Ball::Ball()
{
	m_Veclocity_x = m_Veclocity_y = -SPEED;
	m_Ball = ImageSource::GetInstance()->GetImage(KindOfImage::PinkBall);
	
	m_Left = 100;
	m_Right = m_Left + m_Ball->getWidth();
	m_Top = 250;
	m_Bottom = m_Top + m_Ball->getHeight();

	m_DIR = DIR::NONE;
}

Image* Ball::GetImage()
{
	return m_Ball;
}

void Ball::SetDIR(DIR x)
{
	m_DIR = x;
}

void Ball::Update()
{
	if (m_Left < 0)
	{	
		m_Left = 1;
		m_Right = m_Left + m_Ball->getWidth();
		m_Veclocity_x *= -1;
	}
	else if (m_Right > SCREEN_WIDTH)
	{
		m_Right = SCREEN_WIDTH - 1;
		m_Left = m_Right - m_Ball->getWidth();
		m_Veclocity_x *= -1;
	}

	if (m_Top < 0)
	{
		m_Top = 1;
		m_Bottom = m_Top + m_Ball->getHeight();
		m_Veclocity_y *= -1;
	}
	else if (m_Bottom > SCREEN_HEIGHT)
	{
		m_Bottom = SCREEN_HEIGHT - 1;
		m_Top = m_Bottom - m_Ball->getHeight();
		m_Veclocity_y *= -1;
	}

	if (m_DIR != DIR::NONE)
	{	
		//vi tri truoc khi va cham
		m_Left -= m_Veclocity_x;
		m_Right -= m_Veclocity_x;
		m_Top -= m_Veclocity_y;
		m_Bottom -= m_Veclocity_y;

		switch (m_DIR)
		{
		case DIR::LEFT:
			m_Veclocity_x *= -1;
			
			break;
		case DIR::RIGHT:
			m_Veclocity_x *= -1;
			
			break;
		case DIR::ABOVE:
			m_Veclocity_y *= -1;
			
			break;
		case DIR::BELOW:
			m_Veclocity_y *= -1;
			
			break;
		}
	}
	m_DIR = DIR::NONE;

	m_Left += m_Veclocity_x;
	m_Right += m_Veclocity_x;
	m_Top += m_Veclocity_y;
	m_Bottom += m_Veclocity_y;
}