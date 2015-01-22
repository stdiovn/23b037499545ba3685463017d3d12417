#include "stdafx.h"

#include "MushroomState.h"


MushroomMoving* MushroomMoving::m_instance = 0;

MushroomMoving* MushroomMoving::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new MushroomMoving();
	}

	return m_instance;
}

void MushroomMoving::NextFrame(Enemy* enemy)
{
	int current = enemy->getCurrentFrame();
	current++;

	if (current > EnemySheet::ES_MUSHROOM_DIE - 1)
		current = EnemySheet::ES_MUSHROOM;

	enemy->setCurrentFrame(current);
}

void MushroomMoving::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_MUSHROOM);

	enemy->setVeloc(5, 10);
}

void MushroomMoving::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < ((float)1000 / FPS) * 9)
		return;


	enemy->updateTime();

	if (enemy->getActive())
	{
		if (enemy->getAttack())
		{
			enemy->getStateMachine()->changeState(MushroomDeadByAttacked::getInstance());
			return;
		}
		else if (enemy->getCollision())
		{
			enemy->getStateMachine()->changeState(MushroomDeadByJumped::getInstance());
			return;
		}

		Vec2	position = enemy->getPosition() + enemy->getVeloc();
		enemy->setPosition(position.x, position.y);

		NextFrame(enemy);
	}
}

void MushroomMoving::exit(Enemy* enemy)
{
	enemy->setCollsion(false);
}


//// Dead

MushroomDeadByAttacked* MushroomDeadByAttacked::m_instance = 0;

MushroomDeadByAttacked* MushroomDeadByAttacked::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new MushroomDeadByAttacked();
	}

	return m_instance;
}

void MushroomDeadByAttacked::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_MUSHROOM);
	//enemy->setFlipping(FLIP_Y);
	enemy->setTimeCountDown(15);
	
	enemy->setVeloc(0, 15);
}

void MushroomDeadByAttacked::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < 1000 / FPS * 4) return;

	enemy->updateTime();

	if (enemy->getActive())
	{
		int m_timeCount = enemy->getTimeCountDown();
		m_timeCount--;
		enemy->setTimeCountDown(m_timeCount);

		Vec2 position = enemy->getPosition();
		Vec2 veclocity = enemy->getVeloc();
		veclocity.y -= 3;
		position -= veclocity;

		enemy->setPosition(position.x, position.y);
		
		if (m_timeCount == 0)
			enemy->setActive(false);
	}
}

void MushroomDeadByAttacked::exit(Enemy* enemy)
{
}


// Dead by be jump


MushroomDeadByJumped* MushroomDeadByJumped::m_instance = 0;

MushroomDeadByJumped* MushroomDeadByJumped::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new MushroomDeadByJumped();
	}

	return m_instance;
}

void MushroomDeadByJumped::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_MUSHROOM_DIE);

	enemy->setTimeCountDown(7);

	Vec2 position = enemy->getPosition();
	position.y += 16;
	enemy->setPosition(position.x, position.y);
}

void MushroomDeadByJumped::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < 1000 / FPS * 6) return;

	enemy->updateTime();

	if (enemy->getActive())
	{
		int m_timeCount = enemy->getTimeCountDown();
		m_timeCount--;
		enemy->setTimeCountDown(m_timeCount);

		if (m_timeCount == 0)
			enemy->setActive(false);
	}
}

void MushroomDeadByJumped::exit(Enemy* enemy)
{
}
