#include "stdafx.h"
#include "TurtleState.h"


TurtleMoving* TurtleMoving::m_instance = 0;

TurtleMoving* TurtleMoving::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new TurtleMoving();
	}

	return m_instance;
}

void TurtleMoving::NextFrame(Enemy* enemy)
{
	int current = enemy->getCurrentFrame();
	current++;
	
	if (current > EnemySheet::ES_TURTLE_FLY - 1)
		current = EnemySheet::ES_TURTLE;

	enemy->setCurrentFrame(current);
}

void TurtleMoving::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_TURTLE);
	enemy->setVeloc(6, 10);
}

void TurtleMoving::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < ((float)1000 / FPS) * 9)
		return;

	enemy->updateTime();

	if (enemy->getActive())
	{
		if (enemy->getAttack())
		{
			enemy->getStateMachine()->changeState(TurtleDead::getInstance());
			return;
		}
		else if (enemy->getCollision())
		{
			enemy->getStateMachine()->changeState(TurtleRoll::getInstance());
			return;
		}

		Vec2	position = enemy->getPosition() + enemy->getVeloc();
		enemy->setPosition(position.x, position.y);

		NextFrame(enemy);
	}
}

void TurtleMoving::exit(Enemy* enemy)
{
	enemy->setCollsion(false);
}


//// Dead

TurtleDead* TurtleDead::m_instance = 0;

TurtleDead* TurtleDead::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new TurtleDead();
	}

	return m_instance;
}

void TurtleDead::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_TURTLE);
	//enemy->setFlipping(FLIP_Y);
	enemy->setTimeCountDown(15);
	
	enemy->setVeloc(0, 15);
}

void TurtleDead::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < 1000 / FPS * 4) return;

	enemy->updateTime();

	if (enemy->getActive())
	{
		int time = enemy->getTimeCountDown();
		time--;
		enemy->setTimeCountDown(time);

		Vec2 position = enemy->getPosition();
		Vec2 veclocity = enemy->getVeloc();
		veclocity.y -= 3;
		position -= veclocity;

		enemy->setPosition(position.x, position.y);

		if (time == 0)
			enemy->setActive(false);
	}
}

void TurtleDead::exit(Enemy* enemy)
{
}

// Roll

TurtleRoll* TurtleRoll::m_instance = 0;

TurtleRoll* TurtleRoll::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new TurtleRoll();
	}

	return m_instance;
}

void TurtleRoll::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_TURTLE_ROLL);
	enemy->setTimeCountDown(10);

	Vec2 position = enemy->getPosition();
	position.y += 12;
	enemy->setPosition(position.x, position.y);
}

void TurtleRoll::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < (1000 / FPS) * 8) return;

	enemy->updateTime();


	if (enemy->getActive())
	{
		int m_timeCount = enemy->getTimeCountDown();
		m_timeCount--;
		enemy->setTimeCountDown(m_timeCount);

		if (m_timeCount < 2 && m_timeCount != 0)
			enemy->setCurrentFrame(EnemySheet::ES_FLOWER - 1);
		else if (m_timeCount == 0)
			enemy->getStateMachine()->changeState(TurtleMoving::getInstance());
		else if (enemy->getCollision())
			enemy->getStateMachine()->changeState(TurtleRollMoving::getInstance());
	}
}

void TurtleRoll::exit(Enemy* enemy)
{
	Vec2 position = enemy->getPosition();
	position.y -= 12;
	enemy->setPosition(position.x, position.y);
	enemy->setCollsion(false);
}


// roll moving

TurtleRollMoving* TurtleRollMoving::m_instance = 0;

TurtleRollMoving* TurtleRollMoving::getInstance()
{
	if (m_instance == NULL)
	{
		m_instance = new TurtleRollMoving();
	}

	return m_instance;
}

void TurtleRollMoving::enter(Enemy* enemy)
{
	enemy->setCurrentFrame(EnemySheet::ES_TURTLE_ROLL);

	Vec2 position = enemy->getPosition();
	position.y += 12;
	enemy->setPosition(position.x, position.y);

	enemy->setVeloc(10, 0);
}

void TurtleRollMoving::execute(Enemy* enemy)
{
	if (enemy->getElapseTime() < ((float)1000 / FPS) * 3)
		return;

	enemy->updateTime();

	if (enemy->getActive())
	{
		Vec2	position = enemy->getPosition() + enemy->getVeloc();
		enemy->setPosition(position.x, position.y);
	}
}

void TurtleRollMoving::exit(Enemy* enemy)
{
}
