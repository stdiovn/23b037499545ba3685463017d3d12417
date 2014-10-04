#include "stdafx.h"
#include "STDIO_FW\Video\Image.h"
#include "Square.h"

Square::Square()
{

}

Square::~Square()
{

}

void Square::InitSquare()
{
	m_SqrSpeedX = 3;
	m_SqrSpeedY = 3;
	m_SqrX = 0;
	m_SqrY = 0;
	m_SquareImage = new Image("TenisBall.jpg");
	m_SquareImage->loadImage();
}

int Square::GetSqrX()
{
	return m_SqrX;
}

int Square::GetSqrY()
{
	return m_SqrY;
}

Image* Square::GetSquareImage()
{
	return m_SquareImage;
}

void Square::ConllideSquare()
{

}

void Square::TransferSquare(Rect* R)
{
	//Square conllide with Screen
	m_SqrX += m_SqrSpeedX;
	m_SqrY += m_SqrSpeedY;

	if (m_SqrX >= SRCWidth - SqrWidth)
	{
		m_SqrX = SRCWidth - SqrWidth;
		m_SqrSpeedX = -m_SqrSpeedX;
	}
	else if (m_SqrX <= 0)
	{
		m_SqrX = 0;
		m_SqrSpeedX = -m_SqrSpeedX;
	}
	if (m_SqrY >= SRCHeight - SqrWidth)
	{
		m_SqrY = SRCHeight - SqrWidth;
		m_SqrSpeedY = -m_SqrSpeedY;
	}
	else if (m_SqrY <= 0)
	{
		m_SqrY = 0;
		m_SqrSpeedY = -m_SqrSpeedY;
	}


	//Square conllide with Rect
	if ((m_SqrX + SqrWidth >= R->GetRectX()) && (m_SqrX <= R->GetRectX() + RectWidth))
	{
		if ((m_SqrY + SqrWidth > R->GetRectY()) && (m_SqrY + SqrWidth <= R->GetRectY() + RectHeight))
		{
			m_SqrY = R->GetRectY() - SqrWidth;
		}
		else if ((m_SqrY < R->GetRectY() + RectHeight) && (m_SqrY >= R->GetRectY()))
		{
			m_SqrY = R->GetRectY() + RectHeight;
		}
		if ((m_SqrY + SqrWidth == R->GetRectY()) || (m_SqrY == R->GetRectY() + RectHeight))
		{
			m_SqrSpeedY = -m_SqrSpeedY;
		}
	}

	if ((m_SqrY + SqrWidth >= R->GetRectY()) && (m_SqrY <= R->GetRectY() + RectHeight))
	{
		if ((m_SqrX + SqrWidth > R->GetRectX()) && (m_SqrX <= R->GetRectX()))
		{
			m_SqrX = R->GetRectX() - SqrWidth;
		}
		else if ((m_SqrX < R->GetRectX() + RectWidth) && (m_SqrX > R->GetRectX() + RectWidth - SqrWidth))
		{
			m_SqrX =R->GetRectX() + RectWidth;
		}
		if ((m_SqrX + SqrWidth == R->GetRectX()) || (m_SqrX == R->GetRectX() + RectWidth))
		{
			m_SqrSpeedX = -m_SqrSpeedX;
		}
	}
}

void Square::ReleaseSquare()
{
	m_SquareImage ->~Image();
}