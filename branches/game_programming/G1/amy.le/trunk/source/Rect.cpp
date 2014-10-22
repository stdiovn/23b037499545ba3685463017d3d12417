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

	if (m_X >= SrcWidth - m_Width)
	{
		m_X = SrcWidth - m_Width;
		m_SpeedX = -m_SpeedX;
	}
	else if (m_X <= 0)
	{
		m_X = 0;
		m_SpeedX = -m_SpeedX;
	}

	if (m_Y >= SrcHeight - m_Height)
	{
		m_Y = SrcHeight - m_Height;
		m_SpeedY = -m_SpeedY;
	}
	else if (m_Y <= 0)
	{
		m_Y = 0;
		m_SpeedY = -m_SpeedY;
	}
}

int Rect::GetIsCollide()
{
	return m_IsCollideRect;
}
void Rect::CollideWithRect(Rect* R)
{
	m_IsCollideRect = false;
	if ((m_X + m_Width >= R->GetX()) && (m_X <= R->GetX() + m_Width))
	{
		if ((m_Y + m_Width > R->GetY()) && (m_Y + m_Width < R->GetY() + SrcHeight) && (m_SpeedY > 0))
		{
			m_Y = R->GetY() - m_Width;
		}
		else if ((m_Y < R->GetY() + SrcHeight) && (m_Y > R->GetY()) && (m_SpeedY < 0))
		{
			m_Y = R->GetY() + SrcHeight;
		}
		if ((m_Y + m_Width == R->GetY()) || (m_Y == R->GetY() + SrcHeight))
		{
			m_SpeedY = -m_SpeedY;
			m_IsCollideRect = true;
		}
	}

	if ((m_Y + m_Width >= R->GetY()) && (m_Y <= R->GetY() + SrcHeight))
	{
		if ((m_X + m_Width > R->GetX()) && (m_X < R->GetX()) && (m_SpeedX > 0))
		{
			m_X = R->GetX() - m_Width;
		}
		else if ((m_X < R->GetX() + SrcWidth) && (m_X > R->GetX() + SrcWidth - m_Width) && (m_SpeedX < 0))
		{
			m_X = R->GetX() + SrcWidth;
		}
		if ((m_X + m_Width == R->GetX()) || (m_X == R->GetX() + SrcWidth))
		{
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
