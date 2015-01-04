#include "stdafx.h"

#include "MarioOwnedState.h"
#include "Mario.h"

Mario::Mario(Image* spritesheet, std::vector<Frame>* frameList)
	: BaseObject(spritesheet, frameList){
	m_lives = 3;
	m_isBig = true;
	m_canShoot = false;

	m_stateMachine = new StateMachine<Mario>(this);
	m_stateMachine->changeState(Standing::getInstance());

	m_position = Vec2(30, SCREEN_HEIGHT - 64 - m_frameList->at(m_currentFrame).m_frameRect.height);
	m_worldPosition = m_position;

	m_veloc = Vec2(0, 0);
	m_accel = 1;
	m_isBoost = false;

	m_location = Location::LOC_ON_GROUND;
	m_lastTime = GetTickCount();

	m_isActive = true;
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
	//delete RunJumping::getInstance();
}

void Mario::update()
{
	if(m_lives > 0)
		m_stateMachine->update();

	if(m_veloc.y > 20)
		m_veloc.y = 20;

	

	if((!GetAsyncKeyState(VK_LEFT) && !GetAsyncKeyState(VK_RIGHT)) || GetAsyncKeyState(VK_DOWN))
	{
		static int x = 0;
		x++;

		if(x > 6)
		{
			x = 0;
			if(m_veloc.x < 0)
				m_veloc.x += m_accel;
			else if(m_veloc.x > 0)
				m_veloc.x -= m_accel;
		}
	}



	if(!GetAsyncKeyState(VK_LSHIFT) || m_veloc.y >= 0)
	{
		if(m_position.y < m_groundPosition - m_frameList->at(m_currentFrame).m_frameRect.height)
			m_veloc.y += GRAVITATION;
	}

	if(!GetAsyncKeyState(VK_LSHIFT))
		m_canJump = true;
	


	if(m_worldPosition.x + m_veloc.x >= 0)
	{
		if(m_worldPosition.x + m_veloc.x < SCREEN_WIDTH / 2)
			m_position.x += m_veloc.x;
		m_position.y += m_veloc.y;

		m_worldPosition.x += m_veloc.x;
		m_worldPosition.y = m_position.y;
	}
}

void Mario::draw(Graphics* g)
{
	g->drawRegion(m_spriteSheet, 
		Rect(m_position.x, m_position.y, m_frameList->at(m_currentFrame).m_frameRect.width, m_frameList->at(m_currentFrame).m_frameRect.height), 
		m_frameList->at(m_currentFrame).m_frameRect,
		m_flipping);
}

StateMachine<Mario>* Mario::getStateMachine()
{
	return m_stateMachine;
}