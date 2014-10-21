#include "stdafx.h"
#include "Ball.h"
#define SPEED 3

Ball::Ball()
{
	entities = new Entity();

	entities->activeMoveComponent(SPEED);
	entities->activeRenderComponent(ImageBall);
	entities->activeIsCollision();
}

DIR Ball::UpdateCollisionWindows(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	return entities->isCollisionWindows(SCREEN_WIDTH, SCREEN_HEIGHT);
}

void Ball::UpdateVeclocity(int left, int right, int top, int bottom)
{
	entities->UpdateCollision(left, right,top,bottom);
}

void Ball::Update()
{
	entities->UpdateMovement();
}

Ball::~Ball()
{
	entities->ClearAll();
}

void Ball::Clear()
{
	Ball::~Ball();
}

bool Ball::isCollsionObject(int left, int right, int top, int bottom)
{
	return entities->isCollisionObject(left, right, top, bottom);
}

void Ball::setPosition(int x, int y)
{
	entities->setPosition(x, y);
}

void Ball::Render(Graphics *g)
{
	entities->Render(g);
}