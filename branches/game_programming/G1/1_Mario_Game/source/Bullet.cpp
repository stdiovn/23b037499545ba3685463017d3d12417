#include "stdafx.h"
#include "Bullet.h"
#include "BulletOwnedState.h"

Bullet::Bullet(Image* spritesheet, std::vector<Frame>* frameList) : BaseObject(spritesheet, frameList)
{
	m_isCollision = false;
	m_isActive = false;
	m_time = 0;

	m_stateMachine = new StateMachine<Bullet>(this);
	m_stateMachine->changeState(BulletIdle::getInstance());

	m_vpx = m_vpy = 0;

	m_timeToLive = 30;
}

Bullet::~Bullet()
{
	SAFE_DEL(m_stateMachine);
}

void Bullet::update()
{
	if (getElapseTime() < 1000 / FPS * 2.5)
		return;
	updateTime();

	
	if ( --m_timeToLive <= 0)
	{
		m_isActive = false;
		m_stateMachine->changeState(BulletIdle::getInstance());
		return;
	}

	if (m_stateMachine)
		m_stateMachine->update();

	m_position += m_veloc;
}

StateMachine<Bullet>* Bullet::getStateMachine()
{
	return m_stateMachine;
}

void Bullet::setCamera(int vpx, int vpy)
{
	m_vpx = vpx;
	m_vpy = vpy;
}

void Bullet::draw(Graphics *g)
{
	if (m_isActive)
	{
		if (m_shootDirection == ShootDirection::SHOOT_DIR_RIGHT)
			m_flipping = FLIP_NONE;
		else
			m_flipping = FLIP_X;

		Rect rectFlip = m_frameList->at(m_currentFrame).m_frameRect;
		if (m_flipping == FlippingFlag::FLIP_X)
			rectFlip.x = m_spriteSheet->getWidth() - m_frameList->at(m_currentFrame).m_frameRect.x - m_frameList->at(m_currentFrame).m_frameRect.width;


		Mat3 matrix;
		matrix.setTranslation(m_vpx, m_vpy);
		Vec3 vector(m_position.x, m_position.y, 1);
		vector = vector *  matrix;
		


		g->drawRegion(m_spriteSheet,
			Rect(vector.x, vector.y, m_frameList->at(m_currentFrame).m_frameRect.width, m_frameList->at(m_currentFrame).m_frameRect.height),
			rectFlip,
			m_flipping);
	}
}

