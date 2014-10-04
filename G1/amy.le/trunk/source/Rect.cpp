#include "stdafx.h"
#include "STDIO_FW\Video\Image.h"
#include "STDIO_FW\Core\Application.h"
#include "Rect.h"

#define SRCWidth 800
#define SRCHeight 600
using namespace stdio_fw;

Rect::Rect()
{

}

Rect::~Rect()
{

}

void Rect::InitRect()
{
	m_RectSpeedX = 10;
	m_RectX = 0;
	m_RectY = 500;
	m_RectImage = new Image("TenisNet.jpg");
	m_RectImage->loadImage();
}

int Rect::GetRectX()
{
	return m_RectX;
}

int Rect::GetRectY()
{
	return m_RectY;
}

Image* Rect::GetRectImage()
{
	return m_RectImage;
}

void Rect::ConllideRect()
{
	
}

void Rect::TransferRect(KeyState KeyRight, KeyState KeyLeft)
{
	if (((m_RectX + RectWidth <SRCWidth) && (KeyRight == 1)) || ((m_RectX > 0) && (KeyLeft == 1)))
	{
		m_RectX += m_RectSpeedX;
	}
	if ((m_RectX + RectWidth > SRCWidth) || (m_RectX < 0) || ((m_RectSpeedX < 0) && (KeyRight == 1)) || ((m_RectSpeedX > 0) && (KeyLeft == 1)))
	{
		m_RectSpeedX = -m_RectSpeedX;
	}
}

void Rect::ReleaseRect()
{
	m_RectImage->~Image();
}