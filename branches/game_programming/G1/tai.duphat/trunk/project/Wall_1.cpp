#include "Wall_1.h"
Wall_1::Wall_1(int width, int height)
{
	m_Width = width;
	m_Height = height;
	m_CountImage = 1;

	m_IsColiision = false;
	m_IsDraw = true;
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

bool Wall_1::GetAction()
{
	if (m_IsColiision)
	{
		if (m_CountImage <= 0)
			m_IsDraw = false;
		else
		{
			m_CountImage--;
			m_IsColiision = false;
			temp = KindOfWall::WallOneHit;
		}
	}
	else
	{
		m_IsDraw = true;
	}

	return m_IsDraw;
}

Wall_1::~Wall_1()
{
}
