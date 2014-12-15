#include "stdafx.h"
#include "BrickBreaker/GameObject/MoveObject.h"


MoveObject::~MoveObject()
{
	SAFE_DEL(_velocity);
	SAFE_DEL(_defRect);
	SAFE_DEL(_position);
}


void MoveObject::update(float deltaTime)
{
	Vector2 moveDistance = MICROSEC_TO_SEC(*_velocity * deltaTime);
	if (!outOfScreenHandling(moveDistance))
		*_position += *_velocity;

	_defRect->x = _position->x;
	_defRect->y = _position->y;
}


void MoveObject::moveHorizontal(float velocity)
{
	_velocity->x = velocity;
}


void MoveObject::moveVertical(float velocity)
{
	_velocity->y = velocity;
}


void MoveObject::move(float X_AxisVelo, float Y_AxisVelo)
{
	moveHorizontal(X_AxisVelo);
	moveVertical(Y_AxisVelo);
}


void MoveObject::move(Vector2 velocity)
{
	moveHorizontal(velocity.x);
	moveVertical(velocity.y);
}

Vector2& MoveObject::getPosition()
{
	return *_position;
}


Rect MoveObject::getDefRect()
{
	return *_defRect;
}


bool MoveObject::checkIfBoundWith(Rect objRect)
{
	if (_defRect->x + _defRect->width < objRect.x ||
		_defRect->y + _defRect->height < objRect.y ||
		_defRect->x > objRect.x + objRect.width ||
		_defRect->y > objRect.y + objRect.height)
	{
		return false;
	}

	return true;
}

void MoveObject::setMoveObjectProperties(const Vector2& position, float width, float height,
										Vector2 velocity)
{
	SAFE_DEL(_defRect);
	SAFE_DEL(_position);
	SAFE_DEL(_velocity);

	_position = new Vector2(position);
	_defRect = new Rect(_position->x, _position->y, width, height);
	_velocity = new Vector2(velocity);
}


Vector2 MoveObject::getVelocity()
{
	return *_velocity;
}
