#include "stdafx.h"
#include "BrickBreaker/GameObject/NormalBrick.h"

DWORD NormalBrick::_brickColors[] = { 0xFF0000FF, 0x8C4C5AFF, 0x3D0A5CFF, 0x0B3350FF, 0xC55AABFF, 0x00FF00FF };


NormalBrick::NormalBrick()
{

}

NormalBrick::NormalBrick(Vector2 position, int healthPoints)
{
	setNormalBrickProperties(position, healthPoints);
}

NormalBrick::~NormalBrick()
{

}


void NormalBrick::draw(Graphics* g)
{
	g->setColor(_brickColors[healthPoints_ - 1]);
	g->fillRect(getDefRect());

	g->setColor(BRICK_BORDER_COLOR);
	g->drawRect(getDefRect(), 2);
}


void NormalBrick::update(float deltaTime)
{
}


bool NormalBrick::damaged()
{
	healthPoints_--;
	if (healthPoints_ <= 0)
	{
		crash();
		return BRICK_DESTROYED;
	}

	return BRICK_STILL_LIVE;
}


void NormalBrick::setNormalBrickProperties(Vector2 position, int healthPoints)
{
	Brick::setBrickProperties(position);
	healthPoints_ = healthPoints;
}


void NormalBrick::crash()
{

}


bool NormalBrick::outOfScreenHandling(Vector2 moveDistance)
{
	//UPDATE
	healthPoints_ = 0;
	return true;
}

