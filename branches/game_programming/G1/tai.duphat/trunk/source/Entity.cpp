#include "stdafx.h"
#include "Entity.h"


Entity::Entity()
{
	m_hasCollisionComponent = false;
	m_hasMoveComponent = false;
	m_hasRenderComponent = false;

	m_Image = NULL;
}

Entity::~Entity()
{
	delete m_Image;
}

void Entity::activeRenderComponent(char *PathImage, int x, int y)
{
	m_Image = new Image(PathImage);
	m_Image->loadImage();

	m_x = x;
	m_y = y;

	m_hasRenderComponent = true;
}

void Entity::setPosition(int x, int y)
{
	m_x = x;
	m_y = y;
}

void Entity::deActiveRender()
{
	m_hasRenderComponent = false;
}

void Entity::Render(Graphics *g)
{
	if (m_hasRenderComponent)
	g->drawImage(m_Image, m_x, m_y);
}

int Entity::getHeight()
{
	return m_Image->getHeight();
}

int Entity::getWidth()
{
	return m_Image->getWidth();
}

int Entity::getPositionX()
{
	return m_x;
}

int Entity::getPositionY()
{
	return m_y;
}

void Entity::activeMoveComponent(int speed)
{
	m_speed = speed;

	m_hasMoveComponent = true;
	m_veclocity_vx = m_veclocity_vy = m_speed;
}

void Entity::UpdateSpeedWithKeyBoard(KeyCode key)
{ 
	if (key == KeyCode::KEY_LEFT)
	{
		m_veclocity_vx = -m_speed;
	}
	else if (key == KeyCode::KEY_RIGHT)
	{
		m_veclocity_vx = m_speed;
	}
	else
	{
		m_veclocity_vx = m_veclocity_vy = 0;
	}
}

void Entity::setVeclocity(int vx, int vy)
{
	m_veclocity_vx = vx;
	m_veclocity_vy = vy;
}

bool Entity::isActiveRender()
{
	if (m_hasRenderComponent) return true;

	return false;
}

void Entity::UpdateMovement()
{
	m_x += m_veclocity_vx;
	m_y += m_veclocity_vy;
}

void Entity::activeIsCollision()
{
	m_hasCollisionComponent = true;
}

DIR Entity::isCollisionWindows(int SCREEN_WIDTH, int SCREEN_HEIGHT)
{
	if (m_x < 0)
	{
		m_x = 0;
		m_veclocity_vx *= -1;

		return DIR::LEFT;
	}
	else if (m_x > SCREEN_WIDTH - m_Image->getWidth())
	{
		m_x = SCREEN_WIDTH - m_Image->getWidth();
		m_veclocity_vx *= -1;

		return DIR::RIGHT;
	}
	else if (m_y < 0)
	{
		m_y = 0;
		m_veclocity_vy *= -1;

		return DIR::BELOW;
	}
	else if (m_y > SCREEN_HEIGHT - m_Image->getHeight())
	{
		m_y = SCREEN_HEIGHT - m_Image->getHeight();
		m_veclocity_vy *= -1;

		return DIR::ABOVE;
	}

	return DIR::NONE;
}

bool Entity::isCollisionObject(int left, int right, int top, int bottom)
{
	
	int TamI1_X = m_x + m_Image->getWidth() / 2;
	int TamI1_Y = m_y + m_Image->getHeight() / 2;

	int TamI2_X = (left + right) / 2;
	int TamI2_Y = (bottom + top) / 2;

	if ((abs(TamI1_X - TamI2_X) < (((m_Image->getWidth()) + (right - left)) / 2)
		&& (abs(TamI2_Y - TamI1_Y) < ((m_Image->getHeight()) + (bottom - top)) / 2)))
	{
		return true;
	}

	return false;
}

DIR Entity::getOrientation(int left, int right, int top, int bottom)
{

	int center_x = m_x + m_Image->getWidth() / 2;
	int center_y = m_y + m_Image->getHeight() / 2;

	if (center_x < left)
	{
		return DIR::LEFT;
	}
	else if (center_x > right)
	{
		return DIR::RIGHT;
	}
	else if (center_y < top)
	{
		return DIR::BELOW;
	}
	else if (center_y > bottom)
	{
		return DIR::ABOVE;
	}
}

void Entity::UpdateCollision(int left, int right, int top, int bottom)
{
	if (m_hasCollisionComponent)
	{
		DIR temp = getOrientation(left, right, top, bottom);

		// back position before coliision
		m_x -= m_veclocity_vx;
		m_y -= m_veclocity_vy;

		switch (temp)
		{
		case LEFT:
			m_veclocity_vx *= -1;
			break;
		case RIGHT:
			m_veclocity_vx *= -1;
			break;
		case ABOVE:
			m_veclocity_vy *= -1;
			break;
		case BELOW:
			m_veclocity_vy *= -1;
			break;
		}
	}
}

void Entity::ClearAll()
{
	Entity::~Entity();
}