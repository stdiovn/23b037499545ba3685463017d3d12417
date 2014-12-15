#include "stdafx.h"
#include "BrickBreaker/GameObject/Ball.h"


Ball::Ball(Bat* linkedBat)
{
	Vector2 position = linkedBat->getPosition();
	position.x += linkedBat->getDefRect().width / 2.0f;
	position.y -= linkedBat->getDefRect().height;

	MoveObject::setMoveObjectProperties(position, BALL_SIZE_WIDTH, BALL_SIZE_HEIGHT, SPEED_NO);
	_ballImage = new Image(BALL_RESOURCE);
	ErrorCode err = _ballImage->loadImage();

	if (err != ErrorCode::ERR_NO_ERROR)
	{
		// Do something???
	}

	_linkedBat = linkedBat;
}


Ball::~Ball()
{
	SAFE_DEL(_ballImage);
}


void Ball::draw(Graphics* g)
{
	g->setColor(COLOR_TRANSPARENT);
	g->drawImage(_ballImage, getDefRect());
}


void Ball::update(float deltaTime)
{
	switch (_status)
	{
	case ON_BAT:
		MoveObject::move(_linkedBat->getVelocity());
		break;
	case FLYING:
		if (checkIfBoundWith(_linkedBat->getDefRect()))
		{
			moveVertical(-getVelocity().y);
			moveHorizontal(generateVeloXForTheBallWhenHitBat());
		}
		break;
	default:
		break;
	}

	MoveObject::update(deltaTime);
}


bool Ball::outOfScreenHandling(Vector2 moveDistance)
{
	if (getPosition().x + moveDistance.x < 0)
	{
		getPosition().x = 0;
		moveHorizontal(-getVelocity().x);
		return true;
	}

	if (getPosition().x + getDefRect().width + moveDistance.x > SCREEN_SIZE_WIDTH)
	{
		getPosition().x = SCREEN_SIZE_WIDTH - getDefRect().width;
		moveHorizontal(-getVelocity().x);
		return true;
	}

	if (getPosition().y + moveDistance.y < 0)
	{
		getPosition().y = 0;
		moveVertical(-getVelocity().y);
		return true;
	}

	if (getPosition().y + moveDistance.y > SCREEN_SIZE_HEIGHT)
	{
		_linkedBat->broken();
	}

	return false;
}


void Ball::eventHandling(const map<KeyCode, KeyState>& currentKeyState)
{
	switch (_status)
	{
	case ON_BAT:
		if (currentKeyState.at(CONTROL_A) == KeyState::KEY_PRESSED)
		{
			_status = FLYING;
			srand((unsigned int)time(0));
			MoveObject::move(Vector2((float)SPEED_TO_RIGHT((rand() % (int)(BALL_DEFAULT_SPEED * 2)) - BALL_DEFAULT_SPEED),
									SPEED_TO_TOP(BALL_DEFAULT_SPEED)));
		}
		break;
	case FLYING:
		break;
	default:
		break;
	}
}


float Ball::generateVeloXForTheBallWhenHitBat()
{
	float ballVerticalCenter = getPosition().x + getDefRect().width / 2.0f;
	float batVerticalCenter = _linkedBat->getPosition().x + _linkedBat->getDefRect().width / 2.0f;
	return (getVelocity().x + (ballVerticalCenter - batVerticalCenter) / 4.0f);
}


void Ball::hitBrick()
{
	moveVertical(-getVelocity().y);
}
