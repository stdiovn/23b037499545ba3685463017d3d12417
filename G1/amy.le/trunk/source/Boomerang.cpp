#include "Boomerang.h"
#define BoomerangImage "images.png"
#define BoomerangWidth 50
#define BoomerangHeight 50
Boomerang::Boomerang()
{
}

void Boomerang::Init()
{
	m_Rect = new Rect;
	m_Rect->Init(400, 400, 2, 2, BoomerangWidth, BoomerangHeight);
	m_Image = new Image(BoomerangImage);
	m_Image->loadImage();
}
Rect* Boomerang::GetRect()
{
	return m_Rect;
}
Image* Boomerang::GetImage()
{
	return m_Image;
}

void Boomerang::Tranfer()
{
	m_Rect->TransferOfAutoRect();
}

void Boomerang::Collide(Rect* R)
{
	m_Rect->CollideWithRect(R);
}

void Boomerang::Release()
{
	delete m_Rect;
	delete m_Image;
}
Boomerang::~Boomerang()
{
}
