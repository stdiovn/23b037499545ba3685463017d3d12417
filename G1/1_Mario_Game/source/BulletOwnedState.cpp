#include "stdafx.h"
#include "BulletOwnedState.h"

BulletIdle* BulletIdle::m_instance = 0;

BulletIdle* BulletIdle::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new BulletIdle();
	}

	return m_instance;
}


void BulletIdle::enter(Bullet* bullet)
{
	bullet->setActive(false);
	bullet->setCollsion(false);
}

void BulletIdle::execute(Bullet* bullet)
{
	if (bullet->getActive())
		bullet->getStateMachine()->changeState(BulletMoving::getInstance());
}

void BulletIdle::exit(Bullet* bullet)
{
}

///////////////

BulletMoving* BulletMoving::m_instance = 0;

BulletMoving* BulletMoving::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new BulletMoving();
	}

	return m_instance;
}


void BulletMoving::enter(Bullet* bullet)
{
	bullet->setCurrentFrame(ItemSheet::IS_BULLET);

	m_velocity_x = 24;
	alpha = 3.14159 / 6;

	bullet->setTime(m_velocity_x / 10 * sin(alpha));
}

void BulletMoving::NextFrame(Bullet* bullet)
{
	int temp = bullet->getCurrentFrame();
	temp++;

	if (temp > ItemSheet::IS_BULLET_EXPLODE - 1)
		bullet->setCurrentFrame(ItemSheet::IS_BULLET);
	else
		bullet->setCurrentFrame(temp);
}

void BulletMoving::execute(Bullet* bullet)
{
	if (bullet->getCollision())
	{
		bullet->getStateMachine()->changeState(BulletExplode::getInstance());
	}
	else
	{
		int vx = m_velocity_x * cos(alpha);
		int vy = m_velocity_x * sin(alpha) - 10 * bullet->getTime();

		if (bullet->getShootDirection() == ShootDirection::SHOOT_DIR_RIGHT)
			bullet->setVeloc(vx, -vy);
		else
			bullet->setVeloc(-vx, -vy);

		NextFrame(bullet);

		
		bullet->setTime(bullet->getTime() + 0.2f);
	}
}

void BulletMoving::exit(Bullet* bullet)
{
	bullet->setCollsion(false);
}

/////////////


BulletExplode* BulletExplode::m_instance = 0;

BulletExplode* BulletExplode::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new BulletExplode();
	}

	return m_instance;
}


void BulletExplode::enter(Bullet* bullet)
{
	bullet->setCurrentFrame(ItemSheet::IS_BULLET_EXPLODE);
	bullet->setVeloc(0, 0);
}

void BulletExplode::NextFrame(Bullet* bullet)
{
	int temp = bullet->getCurrentFrame();
	temp++;

	if (temp > ItemSheet::IS_FLAG - 1)
		bullet->setCurrentFrame(ItemSheet::IS_BULLET_EXPLODE);
	else
		bullet->setCurrentFrame(temp);
}

void BulletExplode::execute(Bullet* bullet)
{
	NextFrame(bullet);
	if (bullet->getCurrentFrame() == ItemSheet::IS_BULLET_EXPLODE)
	{
		bullet->setActive(false);
		bullet->getStateMachine()->changeState(BulletIdle::getInstance());
	}	
}

void BulletExplode::exit(Bullet* bullet)
{
}
