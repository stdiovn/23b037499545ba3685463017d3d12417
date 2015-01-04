#include "stdafx.h"
#include "Brick.h"


Brick::Brick(float a)
{
	alive = true;
	possion = a;
}

Brick::Brick()
{
	alive = true;
	possion = 0;
}
Brick::~Brick()
{
}
void Brick::Init()
{
	alive = true;
	im = new Image(BRICK);
	im->loadImage();
	rDynamicObject.x = possion;
	rDynamicObject.y = 10;
	rDynamicObject.height = 50; rDynamicObject.width = 100;
}
void Brick::Update()
{

}

void Brick::Render(Graphics* g)
{
	if (alive == true)g->drawImage(im, rDynamicObject, 0);
}
