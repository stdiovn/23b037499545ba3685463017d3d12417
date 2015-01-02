#include "stdafx.h"

#include "Mario.h"

Mario::Mario(Image* spritesheet, std::vector<Frame>* frameList)
	: BaseObject(spritesheet, frameList){
	m_lives = 2;
	m_canShoot = false;
	m_isActive = true;
	m_state = MarioState::MS_STANDING;

	if(m_lives == 1)
		m_currentFrame = 7;
	else if(!m_canShoot)
		m_currentFrame = 1;
	else
		m_currentFrame = 15;

	m_position = Vec2(30, SCREEN_HEIGHT - 32 * 2 - m_frameList->at(m_currentFrame).m_frameRect.height);
	m_worldPosition = m_position;

	m_veloc = Vec2(0, 2);
	m_accel = 1;
	m_isBoost = false;
}

Mario::~Mario()
{

}

void Mario::update()
{
	if(m_isActive)
	{ 
		m_isBoost = GetAsyncKeyState(VK_LCONTROL);

		////////////////////////////////////////////////////////////////////////
		//Control Animation Time
		DWORD currentTime = GetTickCount();
		m_elapseFrameTime = currentTime - m_lastTime;
		if(m_elapseFrameTime > 1000 / (!m_isBoost ? FRAME_TIME : 2 * FRAME_TIME))
			m_lastTime = currentTime;
		////////////////////////////////////////////////////////////////////////


		
		////////////////////////////////////////////////////////////////////////
		//Handle Input
		KeyCode key;
		if(GetAsyncKeyState(VK_LEFT))
			key = KeyCode::KEY_LEFT;
		else if(GetAsyncKeyState(VK_RIGHT))
			key = KeyCode::KEY_RIGHT;
		else if(GetAsyncKeyState(VK_DOWN))
			key = KeyCode::KEY_DOWN;
		else if(GetAsyncKeyState(VK_LSHIFT))
			key = KeyCode::KEY_UP;
		else
			key = KeyCode::KEY_UNKNOWN;


		if(key == KeyCode::KEY_LEFT || key == KeyCode::KEY_RIGHT || (m_veloc.x != 0))
		{
			if(m_state != MarioState::MS_SITTING)
				run(key);
		}
		else if(key == KeyCode::KEY_DOWN)
		{
			if(m_lives > 1 && (m_state != MarioState::MS_JUMPING || m_state != MarioState::MS_FALLING))
				sit();
		}
		else if(key == KeyCode::KEY_LEFT_SHIFT)
		{
			if(m_state != MarioState::MS_FALLING)
				jump();
		}
		else
			stand();
		////////////////////////////////////////////////////////////////////////



		////////////////////////////////////////////////////////////////////////
		//Set position and worldPosition for scrolling map
		if(m_worldPosition.x + m_veloc.x < SCREEN_WIDTH / 2)
			m_position.x += m_veloc.x;


	/*	if(m_state != MarioState::MS_FALLING)
			m_veloc.y = 0;*/

		m_worldPosition.x += m_veloc.x;
		m_worldPosition.y = m_position.y;

		////////////////////////////////////////////////////////////////////////
	}
}

void Mario::draw(Graphics* g)
{
	g->drawRegion(m_spriteSheet, 
		Rect(m_position.x, m_position.y, m_frameList->at(m_currentFrame).m_frameRect.width, m_frameList->at(m_currentFrame).m_frameRect.height), 
		m_frameList->at(m_currentFrame).m_frameRect,
		m_flipping);
}

void Mario::stand()
{
	if(m_state == MarioState::MS_SITTING)
		m_position.y -= 20;
	m_state = MarioState::MS_STANDING;

	if(m_lives == 1)
		m_currentFrame = MarioSheet::MARIO_STAND;
	else if(!m_canShoot)
		m_currentFrame = MarioSheet::BIG_MARIO_STAND;
	else
		m_currentFrame = MarioSheet::SUPER_MARIO_STAND;
}

void Mario::run(KeyCode key)
{
	if(m_state == MarioState::MS_SITTING)
		m_position.y -= 20;

	if(m_isBoost)
		m_state = MarioState::MS_FASTRUNNING;
	else
		m_state = MarioState::MS_RUNNING;


	////////////////////////////////////////////////////////////////////////
	//Running Animation
	if(m_elapseFrameTime > 1000.0f / (!m_isBoost ? FRAME_TIME : 2 * FRAME_TIME))
	{
		m_elapseFrameTime = 0;
		if(m_lives == 1)
		{
			if(m_frameList->at(m_currentFrame + 1).m_id != "run")
				m_currentFrame = MarioSheet::MARIO_RUN - 1;
		}
		else if(!m_canShoot)
		{
			if(m_frameList->at(m_currentFrame + 1).m_id != "b_run")
				m_currentFrame = MarioSheet::BIG_MARIO_RUN - 1;
		}
		else if(m_frameList->at(m_currentFrame + 1).m_id != "s_run")
			m_currentFrame = MarioSheet::SUPER_MARIO_RUN - 1;

		m_currentFrame++;
		////////////////////////////////////////////////////////////////////////



		if(key == KeyCode::KEY_LEFT)
		{
			if(m_veloc.x > (m_state != MarioState::MS_FASTRUNNING ? -2 : -4))
				m_veloc.x -= m_accel;
			if(m_state != MarioState::MS_FASTRUNNING && m_veloc.x < -2)
				m_veloc.x = -2;

			m_flipping = FlippingFlag::FLIP_Y;
		}
		else if(key == KeyCode::KEY_RIGHT)
		{
			if(m_veloc.x < (m_state != MarioState::MS_FASTRUNNING ? 2 : 4))
				m_veloc.x += m_accel;
			if(m_state != MarioState::MS_FASTRUNNING && m_veloc.x > 2)
				m_veloc.x = 2;

			m_flipping = FlippingFlag::FLIP_NONE;
		}
		else
		{
			if(m_veloc.x > 0)
				m_veloc.x -= m_accel;
			else if(m_veloc.x < 0)
				m_veloc.x += m_accel;
		}
	}
}

void Mario::jump()
{
	
}

void Mario::sit()
{
	m_state = MarioState::MS_SITTING;

	if(!m_canShoot)
		m_currentFrame = MarioSheet::BIG_MARIO_SIT;
	else
		m_currentFrame = MarioSheet::SUPER_MARIO_SIT;
}