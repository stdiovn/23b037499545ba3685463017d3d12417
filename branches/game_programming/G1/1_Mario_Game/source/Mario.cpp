#include "stdafx.h"

#include "MarioOwnedState.h"
#include "Mario.h"

Mario::Mario(Image* spritesheet, std::vector<Frame>* frameList)
	: BaseObject(spritesheet, frameList){
	m_lives = 3;
	m_isBig = false;
	m_canShoot = false;

	m_stateMachine = new StateMachine<Mario>(this);
	m_stateMachine->changeState(Falling::getInstance());

	m_position = Vec2(30, SCREEN_HEIGHT - 64 - m_frameList->at(m_currentFrame).m_frameRect.height - 100);
	m_worldPosition = m_position;

	m_veloc = Vec2(0, 0);
	m_accel = 1;
	m_isBoost = false;

	m_location = Location::LOC_IN_AIR;
	m_lastTime = GetTickCount();

	m_isActive = true;

	m_gun = new Gun(3);
}

Mario::~Mario()
{
	SAFE_DEL(m_stateMachine);

	delete Standing::getInstance();
	delete Running::getInstance();
	delete Sitting::getInstance();
	delete Jumping::getInstance();
	delete Falling::getInstance();
	delete SitJumping::getInstance();

	delete m_gun;
	//delete RunJumping::getInstance();
}

void Mario::update()
{
	if(m_worldPosition.x + m_veloc.x >= 0)
	{
		if (m_worldPosition.x + m_veloc.x < SCREEN_WIDTH / 2)
			m_position.x += m_veloc.x;
		m_position.y += m_veloc.y;

		m_worldPosition.x += m_veloc.x;
		m_worldPosition.y = m_position.y;
	}
}

void Mario::updateVelocity()
{
	if (m_lives > 0)
		m_stateMachine->update();

	if (m_veloc.y > 10)
		m_veloc.y = 10;



	if ((!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT)) || GetAsyncKeyState(VK_DOWN))
	{
		static int x = 0;
		x++;

		if (x > 6)
		{
			x = 0;
			if (m_veloc.x < 0)
				m_veloc.x += m_accel;
			else if (m_veloc.x > 0)
				m_veloc.x -= m_accel;
		}
	}



	if (!GetAsyncKeyState(VK_LSHIFT) || m_veloc.y >= 0)
	{
		//if (m_position.y < m_groundPosition - m_frameList->at(m_currentFrame).m_frameRect.height)
			//m_veloc.y += GRAVITATION;

		//Coder: Tai
		m_veloc.y += GRAVITATION;
	}

	if (!GetAsyncKeyState(VK_LSHIFT))
		m_canJump = true;


	if (GetAsyncKeyState(VK_SPACE) && m_canShoot && getElapseTime() > 1000 / FPS * 10)
	{
		updateTime();

		if (m_flipping == FLIP_X)
			m_gun->shoot(m_worldPosition.x, m_worldPosition.y, ShootDirection::SHOOT_DIR_LEFT);
		else
			m_gun->shoot(m_worldPosition.x + m_frameList->at(m_currentFrame).m_frameRect.width, m_worldPosition.y, ShootDirection::SHOOT_DIR_RIGHT);
	}

	m_gun->update();
}

void Mario::draw(Graphics* g)
{
	Rect rectFlip = m_frameList->at(m_currentFrame).m_frameRect;
	if (m_flipping == FlippingFlag::FLIP_X)
		rectFlip.x = m_spriteSheet->getWidth() - m_frameList->at(m_currentFrame).m_frameRect.x - m_frameList->at(m_currentFrame).m_frameRect.width;

	g->drawRegion(m_spriteSheet,
		Rect(m_position.x, m_position.y, m_frameList->at(m_currentFrame).m_frameRect.width, m_frameList->at(m_currentFrame).m_frameRect.height),
		rectFlip,
		m_flipping);


	if (m_worldPosition.x >= SCREEN_WIDTH / 2)
		m_gun->setCamera(-(m_worldPosition.x - SCREEN_WIDTH / 2), 0);
	m_gun->draw(g);
}

StateMachine<Mario>* Mario::getStateMachine()
{
	return m_stateMachine;
}

void Mario::setIsBig(bool x)
{
	m_isBig = x;

	if (x)
	{
		setCurrentFrame(MarioSheet::SUPER_MARIO_STAND);

		m_position.y = m_groundPosition - m_frameList->at(m_currentFrame).m_frameRect.height;
		m_worldPosition.y = m_position.y;
	}
}