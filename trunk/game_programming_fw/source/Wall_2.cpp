#include "stdafx.h"
#include "Wall_2.h"


Wall_2::Wall_2(int width, int height) : Wall_1(width, height)
{
	m_CountImage = 2;
	temp = KindOfImage::WallTwoHit;
	m_Image = ImageSource::GetInstance()->GetImage(temp);
}


Wall_2::~Wall_2()
{
}
