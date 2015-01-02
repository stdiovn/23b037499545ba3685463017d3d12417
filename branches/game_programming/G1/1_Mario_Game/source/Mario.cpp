#include "stdafx.h"

#include "Mario.h"

void Mario::update()
{
	if(m_isActive)
	{
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
		/*else if(GetAsyncKeyState(VK_DOWN))
			key = KeyCode::KEY_DOWN;
		else if(GetAsyncKeyState(VK_UP))
			key = KeyCode::KEY_UP;*/
		else
			key = KeyCode::KEY_UNKNOWN;

		m_isBoost = GetAsyncKeyState(VK_LCONTROL);


		if(key == KeyCode::KEY_LEFT || key == KeyCode::KEY_RIGHT || (key == KeyCode::KEY_UNKNOWN && m_veloc != 0))
			run(key);
		else
			stand();
		////////////////////////////////////////////////////////////////////////



		////////////////////////////////////////////////////////////////////////
		//Set position and worldPosition for scrolling map
		if(m_worldPosition.x + m_veloc < SCREEN_WIDTH / 2)
			m_position.x += m_veloc;
		m_position.y = SCREEN_HEIGHT - 32 * 2 - m_frameList->at(m_currentFrame).m_frameRect.height;

		m_worldPosition.x += m_veloc;
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
	if(m_state != MarioState::MS_STANDING)
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
	if(m_state != MarioState::MS_RUNNING)
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
			if(m_veloc > (!m_isBoost ? -2 : -4))
				m_veloc -= m_accel;
			if(!m_isBoost && m_veloc < -2)
				m_veloc = -2;

			m_flipping = FlippingFlag::FLIP_Y;
		}
		else if(key == KeyCode::KEY_RIGHT)
		{
			if(m_veloc < (!m_isBoost ? 2 : 4))
				m_veloc += m_accel;
			if(!m_isBoost && m_veloc > 2)
				m_veloc = 2;

			m_flipping = FlippingFlag::FLIP_NONE;
		}
		else
		{
			if(m_veloc > 0)
				m_veloc -= m_accel;
			else if(m_veloc < 0)
				m_veloc += m_accel;
		}
	}
}

void Mario::jump()
{

}

void Mario::sit()
{

}