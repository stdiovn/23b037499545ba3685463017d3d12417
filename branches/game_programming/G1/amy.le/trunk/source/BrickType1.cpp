#include "stdafx.h"
#include "STDIO_FW\Video\Image.h"
#include "STDIO_FW\Core\Application.h"
#include "BrickType1.h"
#define BrickImage1 "Brick1.png"
#define BrickImage2 "Brick2.png"

Type1::Type1()
{
}
Type1::~Type1()
{

}
void Type1::InitBrick()
{
	m_Live = 2;
	m_BrickX = 10 + BrickWidth * m_Countj;
	m_BrickY = BrickHeight * m_Counti;
	m_BrickImage1 = new Image(BrickImage1);
	m_BrickImage1->loadImage();
	m_BrickImage2 = new Image(BrickImage2);
	m_BrickImage2->loadImage();
}
int Type1::GetBrickX()
{
	return m_BrickX;
}
int Type1::GetBrickY()
{
	return m_BrickY;
}
int Type1::GetLive()
{
	return m_Live;
}
void Type1::SetLive()
{
	m_Live --;
}
void Type1::SetCounti(int i)
{
	m_Counti = i;
}
void Type1::SetCountj(int j)
{
	m_Countj = j;
}
Image* Type1::GetImage()
{
	if (m_Live == 2)
	{
		return m_BrickImage1;
	}
	else if (m_Live == 1)
	{
		return m_BrickImage2;
	}
}

void Type1::ReleaseBrick()
{

}