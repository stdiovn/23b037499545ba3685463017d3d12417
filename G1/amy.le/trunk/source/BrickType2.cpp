#include "stdafx.h"
#include "STDIO_FW\Video\Image.h"
#include "STDIO_FW\Core\Application.h"
#include "BrickType2.h"
#define BrickImage3 "Brick3.png"

Type2::Type2()
{
}
Type2::~Type2()
{

}
void Type2::InitBrick()
{
	m_Live = 1;
	m_BrickX = 10 + BrickWidth * m_Countj;
	m_BrickY = BrickHeight * m_Counti;
	m_BrickImage3 = new Image(BrickImage3);
	m_BrickImage3->loadImage();
}
int Type2::GetBrickX()
{
	return m_BrickX;
}
int Type2::GetBrickY()
{
	return m_BrickY;
}
int Type2::GetLive()
{
	return m_Live;
}
void Type2::SetLive()
{
	m_Live--;
}
void Type2::SetCounti(int i)
{
	m_Counti = i;
}

void Type2::SetCountj(int j)
{
	m_Countj = j;
}

Image* Type2::GetImage()
{
	return m_BrickImage3;
}
void Type2::ReleaseBrick()
{

}