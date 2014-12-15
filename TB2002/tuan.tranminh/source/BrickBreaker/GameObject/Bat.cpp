#include "stdafx.h"
#include "BrickBreaker/GameObject/Bat.h"


Bat::Bat()
{
	MoveObject::setMoveObjectProperties(DEFAULT_START_POINT, DEFAULT_BAT_WIDTH, DEFAULT_BAT_HEIGHT, SPEED_NO);
	_lifeRemaining = DEFAULT_LIFE_NUM;
}

Bat::~Bat()
{

}

void Bat::draw(Graphics* g)
{
	g->setColor(DEFAULT_BAT_COLOR);
	g->fillRect(getDefRect());
}

void Bat::update(float deltaTime)
{
	MoveObject::update(deltaTime);
}

void Bat::eventHandling(const map<KeyCode, KeyState>& currentKeyState)
{
	if (currentKeyState.at(CONTROL_MOVE_LEFT) == KeyState::KEY_PRESSED)
		moveHorizontal(SPEED_TO_LEFT(DEFAULT_BAT_MOVESPEED));
	else
		if (currentKeyState.at(CONTROL_MOVE_RIGHT) == KeyState::KEY_PRESSED)
			moveHorizontal(SPEED_TO_RIGHT(DEFAULT_BAT_MOVESPEED));
		else
			moveHorizontal(SPEED_NO.x);
}


bool Bat::outOfScreenHandling(Vector2 moveDistance)
{
	if (getPosition().x + moveDistance.x < 0)
	{
		getPosition().x = 0;
		return true;
	}

	if (getPosition().x + getDefRect().width + moveDistance.x > SCREEN_SIZE_WIDTH)
	{
		getPosition().x = SCREEN_SIZE_WIDTH - getDefRect().width;
		return true;
	}

	return false;
}


void Bat::broken()
{
	_lifeRemaining -= 1;
	MoveObject::setMoveObjectProperties(DEFAULT_START_POINT, DEFAULT_BAT_WIDTH, DEFAULT_BAT_HEIGHT, SPEED_NO);
}


bool Bat::ifLoose()
{
	return (_lifeRemaining < 0);
}
