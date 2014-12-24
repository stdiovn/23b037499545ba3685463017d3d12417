#include "stdafx.h"
#include "Background.h"
#include "Resources.h"
#include "GameDefine.h"


Background::Background()
{
	m_Position.x = 0;
	m_Position.y = 0;
	m_Image = &_image_Background;
}

Background::Background(Image *_image_Backgound)
{
	m_Position.x = 0;
	m_Position.y = 0;
	m_Image = &_image_Backgound;
}


Background::~Background()
{
	delete m_Image;
}


void Background::Update(float deltaTime)
{
}


void Background::Render(Graphics *g)
{
	g->drawImage(*m_Image, Rect(0, 0, 800, 600));
}