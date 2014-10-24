#include "stdafx.h"
#include "STDIO_FW\Core\Application.h"
#include "Rect.h"
#define SrcWidth 800
#define SrcHeight 600

Rect::Rect()
{
}
void Rect::Init(int x, int y, int speedx, int speedy, int width, int height)
{
	m_X = x;
	m_Y = y;
	m_SpeedX = speedx;
	m_SpeedY = speedy;
	m_Width = width;
	m_Height = height;
	m_IsCollideRect = false;
}
int Rect::GetX()
{
	return m_X;
}
int Rect::GetY()
{
	return m_Y;
}
void Rect::SetX(int x)
{
	m_X = x;
}
void Rect::SetY(int y)
{
	m_Y = y;
}
int Rect::GetSpeedX()
{
	return m_SpeedX;
}
int Rect::GetSpeedY()
{
	return m_SpeedY;
}
void Rect::SetSpeedX(int speedx)
{
	m_SpeedX = speedx;
}
void Rect::SetSpeedY(int speedy)
{
	m_SpeedY = speedy;
}
void Rect::TransferOfControlledRect(KeyState KeyLeft, KeyState KeyRight)
{
	if ((KeyRight == 1) && (m_X + m_Width < SrcWidth))
	{
		m_X += m_SpeedX;
		if (m_X > SrcWidth - m_Width)
		{
			m_X = SrcWidth - m_Width;
		}
	}
	else if ((KeyLeft == 1) && (m_X > 0))
	{
		m_X -= m_SpeedX;
		if (m_X < 0)
		{
			m_X = 0;
		}
	}
}
void Rect::TransferOfAutoRect()
{
	m_X += m_SpeedX;
	m_Y += m_SpeedY;

	if ((m_X >= SrcWidth - m_Width) || (m_X <= 0))
	{
		m_SpeedX = -m_SpeedX;
		if (m_SpeedX > 0)
		{
			m_X = SrcWidth - m_Width;
		}
		else
		{
			m_X = 0;
		}
	}
	
	if ((m_Y >= SrcHeight - m_Height) || (m_Y <= 0) )
	{
		m_SpeedY = -m_SpeedY;
		if (m_SpeedY > 0)
		{
			m_Y = SrcHeight - m_Height;
		}
		else
		{
			m_Y = 0;
		}
	}
}

int Rect::GetIsCollide()
{
	return m_IsCollideRect;
}

int Rect::GetWidth()
{
	return m_Width;
}

int Rect::GetHeight()
{
	return m_Height;
}

void Rect::CollideWithRect(Rect* R)
{
	m_IsCollideRect = false;
	if ((m_X + m_Width >= R->GetX()) && (m_X + m_Width <= R->GetX() + R->GetWidth()))
	{
		if ((m_Y + m_Height >= R->GetY()) && (m_Y + m_Height <= R->GetY() + R->GetHeight()))
		{
			if (m_SpeedY > 0)
			{
				m_Y = R->GetY() - m_Height;
			}
			else
			{
				m_Y = R->GetY() + R->GetHeight() - m_Height;
			}
			m_SpeedY = -m_SpeedY;
			m_IsCollideRect = true;
		}
	}

	if ((m_Y + m_Height >= R->GetY()) && (m_Y + m_Height <= R->GetY() + R->GetHeight()))
	{
		if ((m_X + m_Width >= R->GetX()) && (m_X + m_Width <= R->GetX() + R->GetWidth()))
		{
			if (m_SpeedX > 0)
			{
				m_X = R->GetX() - m_Width;
			}
			else
			{
				m_X = R->GetX() + R->GetWidth() - m_Width;
			}
			m_SpeedX = -m_SpeedX;
			m_IsCollideRect = true;
		}	
	}
}

void Rect::Release()
{

}

Rect::~Rect()
{
}
