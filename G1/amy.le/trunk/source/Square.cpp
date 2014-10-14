#include "stdafx.h"
#include "STDIO_FW\Video\Image.h"
#include "Square.h"

#define TenisBall "images.png"
Square::Square()
{

}

Square::~Square()
{

}

void Square::InitSquare()
{
	m_SqrSpeedX = 2;
	m_SqrSpeedY = 2;
	m_SqrX = 400;
	m_SqrY = 400;
	IsConllideRect = false;
	IsConllideBrick = false;
	m_SquareImage = new Image(TenisBall);
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

bool Square::GetIsConllideRect()
{
	return IsConllideRect;
}
bool Square::GetIsConllideBrick()
{
	return IsConllideBrick;
}

void Square::ConllideSquare(Rect* R,Brick* B)
{
	//Square conllide with Rect
	IsConllideRect = false;
	if ((m_SqrX + SqrWidth >= R->GetRectX()) && (m_SqrX <= R->GetRectX() + RectWidth))
	{
		if ((m_SqrY + SqrWidth > R->GetRectY()) && (m_SqrY + SqrWidth < R->GetRectY() + RectHeight) && (m_SqrSpeedY > 0))
		{
			m_SqrY = R->GetRectY() - SqrWidth;
		}
		else if ((m_SqrY < R->GetRectY() + RectHeight) && (m_SqrY > R->GetRectY()) && (m_SqrSpeedY < 0))
		{
			m_SqrY = R->GetRectY() + RectHeight;
		}
		if ((m_SqrY + SqrWidth == R->GetRectY()) || (m_SqrY == R->GetRectY() + RectHeight))
		{
			m_SqrSpeedY = -m_SqrSpeedY;
			IsConllideRect = true;
		}
	}

	if ((m_SqrY + SqrWidth >= R->GetRectY()) && (m_SqrY <= R->GetRectY() + RectHeight))
	{
		if ((m_SqrX + SqrWidth > R->GetRectX()) && (m_SqrX < R->GetRectX()) && (m_SqrSpeedX > 0))
		{
			m_SqrX = R->GetRectX() - SqrWidth;
		}
		else if ((m_SqrX < R->GetRectX() + RectWidth) && (m_SqrX > R->GetRectX() + RectWidth - SqrWidth) && (m_SqrSpeedX < 0))
		{
			m_SqrX = R->GetRectX() + RectWidth;
		}
		if ((m_SqrX + SqrWidth == R->GetRectX()) || (m_SqrX == R->GetRectX() + RectWidth))
		{
			m_SqrSpeedX = -m_SqrSpeedX;
			IsConllideRect = true;
		}
	}
	IsConllideBrick = false;
	//Square conllide with Brick
	if ((m_SqrX + SqrWidth >= B->GetBrickX()) && (m_SqrX <= B->GetBrickX() + BrickWidth))
	{
		if ((m_SqrY + SqrWidth > B->GetBrickY()) && (m_SqrY + SqrWidth < B->GetBrickY() + BrickHeight) && (m_SqrSpeedY > 0))
		{
			m_SqrY = B->GetBrickY() - SqrWidth;
		}
		else if ((m_SqrY < B->GetBrickY() + BrickHeight) && (m_SqrY > B->GetBrickY()) && (m_SqrSpeedY < 0))
		{
			m_SqrY = B->GetBrickY() + BrickHeight;
		}
		if ((m_SqrY + SqrWidth == B->GetBrickY()) || (m_SqrY == B->GetBrickY() + BrickHeight))
		{
			m_SqrSpeedY = -m_SqrSpeedY;
			IsConllideBrick = true;
			B->SetLive();
		}
	}

	if ((m_SqrY + SqrWidth >= B->GetBrickY()) && (m_SqrY <= B->GetBrickY() + BrickHeight))
	{
		if ((m_SqrX + SqrWidth > B->GetBrickX()) && (m_SqrX < B->GetBrickX()) && (m_SqrSpeedX > 0))
		{
			m_SqrX = B->GetBrickX() - SqrWidth;
		}
		else if ((m_SqrX < B->GetBrickX() + BrickWidth) && (m_SqrX > B->GetBrickX() + BrickWidth - SqrWidth) && (m_SqrSpeedX < 0))
		{
			m_SqrX = B->GetBrickX() + BrickWidth;
		}
		if ((m_SqrX + SqrWidth == B->GetBrickX()) || (m_SqrX == B->GetBrickX() + BrickWidth))
		{
			m_SqrSpeedX = -m_SqrSpeedX;
			IsConllideBrick = true;
			B->SetLive();
		}
	}
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
}

void Square::ReleaseSquare()
{
	m_SquareImage ->~Image();
}