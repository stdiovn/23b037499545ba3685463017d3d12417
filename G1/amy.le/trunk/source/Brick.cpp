#include "Brick.h"

#define BrickImage1 "Brick1.png"
#define BrickImage2 "Brick2.png"
#define BrickImage3 "Brick3.png"
#define BrickWidth 60
#define BrickHeight 90
Brick::Brick()
{
}

void Brick::Init()
{
	m_IsAlive = 2;
	m_Rect = new Rect;
	m_Rect->Init(10 + BrickWidth * m_Countj, BrickHeight * m_Counti, 0, 0, BrickWidth, BrickHeight);
	m_Image1 = new Image(BrickImage1);
	m_Image1->loadImage();
	m_Image2 = new Image(BrickImage2);
	m_Image2->loadImage();
	m_Image3 = new Image(BrickImage3);
	m_Image3->loadImage();
}
Rect* Brick::GetRect()
{
	return m_Rect;
}
Image* Brick::GetImage()
{
	if (m_IsAlive == 2)
	{
		return m_Image1;
	}
	else if (m_IsAlive == 1)
	{
		return m_Image2;
	}
	else if (m_IsAlive == 0)
	{
		return m_Image3;
	}
}

void Brick::SetCounti(int i)
{
	m_Counti = i;
}

void Brick::SetCountj(int j)
{
	m_Countj = j;
}

void Brick::Conllide(Rect* R)
{
	m_Rect->CollideWithRect(R);
	if (m_Rect->GetIsCollide())
	{
		m_IsAlive--;
	}
}

int Brick::GetIsAlive()
{
	return m_IsAlive;
}

void Brick::SetIsAlive(int IsAlive)
{
	m_IsAlive = IsAlive;
}
void Brick::Release()
{
	delete m_Rect;
	delete m_Image1;
	delete m_Image2;
}


Brick::~Brick()
{
}
