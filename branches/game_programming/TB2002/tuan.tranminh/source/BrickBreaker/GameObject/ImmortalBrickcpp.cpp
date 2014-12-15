#include "stdafx.h"
#include "BrickBreaker/GameObject/ImmortalBrick.h"

ImmortalBrick::ImmortalBrick(Vector2 position)
{
	setImmortalBrickProperties(position);
}

ImmortalBrick::~ImmortalBrick()
{
}


void ImmortalBrick::draw(Graphics* g)
{
	g->setColor(IMMORTAL_BRICK_COLOR);
	g->fillRect(getDefRect());
}

void ImmortalBrick::update(float deltaTime)
{
}

bool ImmortalBrick::damaged()
{
	return BRICK_STILL_LIVE;
}

bool ImmortalBrick::outOfScreenHandling(Vector2 moveDistance)
{
	_isDead = BRICK_DESTROYED;
	return false;
}


void ImmortalBrick::setImmortalBrickProperties(Vector2 position)
{
	Brick::setBrickProperties(position);
	_isDead = BRICK_STILL_LIVE;
}
