#include "stdafx.h"
#include "Bar.h"


Bar::Bar()
{
}


Bar::~Bar()
{
}
void Bar::Init()
{
	im = new Image(BAR);
	im->loadImage();
	rDynamicObject.x = 800-630;
	rDynamicObject.y = 600-35;
	//rDynamicObject.y = 600 - 400;
	rDynamicObject.height = 35;
	rDynamicObject.width = 408;
}
void Bar::Update()
{

}

void Bar::Render(Graphics* g)
{
	g->drawImage(im, rDynamicObject, 0);
}

void Bar::moveleft()
{
	Sleep(2);
	rDynamicObject.x--;
	if (rDynamicObject.x < 0)rDynamicObject.x = 0;
}

void Bar::moveright()
{
	Sleep(2);
	rDynamicObject.x++;
	if (rDynamicObject.x > 800 - 408)rDynamicObject.x = 800 - 408;
}