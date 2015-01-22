#include "stdafx.h"
#include "FlowerState.h"


FlowerIdle* FlowerIdle::m_instance = 0;

FlowerIdle* FlowerIdle::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new FlowerIdle();
	}

	return m_instance;
}


void FlowerIdle::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_FLOWER);
	enemy->setTimeCountDown(20);
	enemy->updateTime();
}

void FlowerIdle::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < ((float)1000 / FPS) * 10)
		return;

	if (enemy->getActive())
	{
		int m_timeCount = enemy->getTimeCountDown() - 1;
		enemy->setTimeCountDown(m_timeCount);

		if (m_timeCount == 0)
			enemy->getStateMachine()->changeState(FlowerGrow::getInstance());
	}

	enemy->updateTime();
}

void FlowerIdle::exit(Enemy* enemy)
{
}



//////////////////


FlowerGrow* FlowerGrow::m_instance = 0;

FlowerGrow* FlowerGrow::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new FlowerGrow();
	}

	return m_instance;
}

void FlowerGrow::NextFrame(Enemy* enemy)
{
	int current = enemy->getCurrentFrame();
	current++;

	if (current > EnemySheet::ES_MUSHROOM - 1)
		current = EnemySheet::ES_FLOWER;

	enemy->setCurrentFrame(current);
}

void FlowerGrow::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_FLOWER);
	enemy->updateTime();
	enemy->setTimeCountDown(40);
}

void FlowerGrow::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < ((float)1000 / FPS) * 9)
		return;

	if (enemy->getActive())
	{
		int m_timeCount = enemy->getTimeCountDown() - 1;
		enemy->setTimeCountDown(m_timeCount);

		Vec2 position = enemy->getPosition();

		if (m_timeCount >= 26)
		{
			position.y -= enemy->getRect().height / 12;
		}
		else if (m_timeCount <= 14 && m_timeCount != 0)
		{	
			position.y += enemy->getRect().height / 12;
		}
		else if (m_timeCount == 0)
		{
			enemy->getStateMachine()->changeState(FlowerIdle::getInstance());
		}

		if (enemy->getAttack())
			enemy->getStateMachine()->changeState(FlowerDead::getInstance());

		enemy->setPosition(position.x, position.y);
		NextFrame(enemy);
	}

	enemy->updateTime();
}

void FlowerGrow::exit(Enemy* enemy)
{
}

///////////////

FlowerDead* FlowerDead::m_instance = 0;

FlowerDead* FlowerDead::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new FlowerDead();
	}

	return m_instance;
}


void FlowerDead::enter(Enemy* enemy)
{
}

void FlowerDead::execute(Enemy* enemy)
{
	enemy->setActive(false);
}

void FlowerDead::exit(Enemy* enemy)
{
}