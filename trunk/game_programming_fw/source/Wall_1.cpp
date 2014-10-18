#include "stdafx.h"
#include "Wall_1.h"
Wall_1::Wall_1(int width, int height)
{
	m_Width = width;
	m_Height = height;
	m_CountImage = 1;

	temp = KindOfImage::WallOneHit;

	m_Image = ImageSource::GetInstance()->GetImage(temp);
}

int Wall_1::GetWidth()
{
	return m_Width;
}

int Wall_1::GetHeight()
{
	return m_Height;
}

Image* Wall_1::GetImage()
{
	return m_Image;
}

void Wall_1::UpdateImage()
{
	m_Image = ImageSource::GetInstance()->GetImage(temp);
}

bool Wall_1::GetActionDraw()
{
	if (m_CountImage <= 1)
		return false;
	else
	{
		m_CountImage--;
		temp = KindOfImage::WallOneHit;

		return true;
	}
}

Wall_1::~Wall_1()
{
}
