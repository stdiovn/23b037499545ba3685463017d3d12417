#include "stdafx.h"
#include "Background.h"
#include "Resources.h"

Background::Background()
{
	mPosition.x = 0;
	mPosition.y = 0;
	mImage = &_image_BackGround;
}

Background::Background(Image *_image_Backgound)
{
	mPosition.x = 0;
	mPosition.y = 0;
	mImage = &_image_Backgound;
}


Background::~Background()
{
	delete mImage;
}


void Background::Update()
{
}


void Background::Render(Graphics *g)
{
	g->drawImage(*mImage, Rect(0, 0, 800, 600));
}