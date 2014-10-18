#include "stdafx.h"
#include "ThanhMove.h"
#define SPEED 3

ThanhMove::ThanhMove()
{
	m_Move = ImageSource::GetInstance()->GetImage(KindOfImage::Thanh);
	m_Left = 100;
	m_Right = m_Left + m_Move->getWidth();
	m_Top = 460;
	m_Bottom = m_Top + m_Move->getHeight();

	m_Speed = 0;
	//m_Direct = Move::NONE;
}


void ThanhMove::Update(KeyCode key)
{
	if (key == KeyCode::KEY_LEFT)
	{
		m_Speed = -SPEED;
	}
	else if (key == KeyCode::KEY_RIGHT)
	{
		m_Speed = SPEED;
	}
	else
	{
		m_Speed = 0;
	}

	if (m_Left < 0 || m_Right > SCREEN_WIDTH)
	{
		if (m_Left < SCREEN_WIDTH) m_Left = 0;
		else m_Left = SCREEN_WIDTH;
		m_Speed = 0;
	}

	m_Left += m_Speed;
	m_Right += m_Speed;
}

Image* ThanhMove::GetImage()
{
	return m_Move;
}

ThanhMove::~ThanhMove()
{
}
