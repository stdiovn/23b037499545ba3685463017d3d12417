#include "stdafx.h"
#include "ResourcesManager.h"
#include "TurtleState.h"
#include "MushroomState.h"
#include "FlowerState.h"

Enemy::Enemy(EnemysType type, Vec2 position) : BaseObject(ResourcesManager::getInstance()->getResource(SpriteSheet::SHEET_ENEMIES), 
															ResourcesManager::getInstance()->getFrameList(SpriteSheet::SHEET_ENEMIES))
{
	m_isActive = false;
	m_position = position;

	m_isCollision = false;
	m_beAttacked = false;

	m_typeEnemy = type;

	m_stateMachine = new StateMachine<Enemy>(this);

	switch (type)
	{
	case ET_MUSHROOM:
		m_stateMachine->changeState(MushroomMoving::getInstance());
		break;
	case ET_TURTLE:
		m_stateMachine->changeState(TurtleMoving::getInstance());
		break;
	case ET_TURTLE_FLY:
		break;
	case ET_FLOWER:
		m_stateMachine->changeState(FlowerIdle::getInstance());
		break;
	}	
}

void Enemy::update()
{
	if (m_stateMachine)
		m_stateMachine->update();
}

void Enemy::draw(Graphics* g)
{
	if (m_isActive)
	{
		Mat3 matrix;
		matrix.setTranslation(m_vpx, m_vpy);
		Vec3 vector(m_position.x, m_position.y, 1);
		vector = vector *  matrix;

		g->drawRegion(m_spriteSheet,
			Rect(vector.x, vector.y, m_frameList->at(m_currentFrame).m_frameRect.width, m_frameList->at(m_currentFrame).m_frameRect.height),
			m_frameList->at(m_currentFrame).m_frameRect,
			m_flipping);
	}
}

Enemy::~Enemy()
{
	SAFE_DEL(m_stateMachine);

	/*delete TurtleDead::getInstance();
	delete TurtleMoving::getInstance();
	delete TurtleRoll::getInstance();

	delete MushroomDeadByAttacked::getInstance();
	delete MushroomDeadByJumped::getInstance();
	delete MushroomMoving::getInstance();

	delete FlowerDead::getInstance();
	delete FlowerGrow::getInstance();
	delete FlowerIdle::getInstance();*/
}


void Enemy::setCamera(int vpx, int vpy)
{
	m_vpx = vpx;
	m_vpy = vpy;
}