#include "ThanhMove.h"
#define SPEED 4

ThanhMove::ThanhMove(int x, int y)
{
	m_Move = new Entity();
	m_Move->activeRenderComponent(MoveImage, x, y);

	m_Move->activeMoveComponent(SPEED);
	m_Move->setVeclocity(SPEED, 0);

	m_Move->activeIsCollision();

	m_Y = y;
}

void ThanhMove::Render(Graphics *g)
{
	m_Move->Render(g);
}

void ThanhMove::UpdateSpeedKeyBoard(KeyCode key)
{
	m_Move->UpdateSpeedWithKeyBoard(key);
	m_Move->UpdateMovement();
}

void ThanhMove::UpdateCollisionWithWindows(int width, int height)
{
	switch (m_Move->isCollisionWindows(width, height))
	{
	case DIR::LEFT:
		m_Move->setPosition(0, m_Y);
		break;
	case DIR::RIGHT:
		m_Move->setPosition(width - m_Move->getWidth(), m_Y);
		break;
	}
}

int ThanhMove::getHeight()
{
	return m_Move->getHeight();
}

int ThanhMove::getWidth()
{
	return m_Move->getWidth();
}

int ThanhMove::getPositionX()
{
	return m_Move->getPositionX();
}

int ThanhMove::getPositionY()
{
	return m_Move->getPositionY();
}

ThanhMove::~ThanhMove()
{
	m_Move->ClearAll();
}

void ThanhMove::Clear()
{
	ThanhMove::~ThanhMove();
}
