#include "stdafx.h"

#include "Mario.h"

void Mario::update()
{
	if(m_isActive)
	{
		float currentTime = GetTickCount();
		m_elapseFrameTime = currentTime - m_lastTime;
		if(m_elapseFrameTime > 1000 / FRAME_TIME)
			m_lastTime = currentTime;

		KeyCode key;

		if(GetAsyncKeyState(VK_LEFT))
			key = KeyCode::KEY_LEFT;
		else if(GetAsyncKeyState(VK_RIGHT))
			key = KeyCode::KEY_RIGHT;
		else
			key = KeyCode::KEY_UNKNOWN;

		if(key == KeyCode::KEY_LEFT || key == KeyCode::KEY_RIGHT || (key == KeyCode::KEY_UNKNOWN && m_veloc != 0))
			run(key);
		else
			stand();

		m_position.x += m_veloc;
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

	if(m_elapseFrameTime > 1000.0f / FRAME_TIME)
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

		if(key == KeyCode::KEY_LEFT)
		{
			if(m_veloc > -3)
				m_veloc -= m_accel;
			m_flipping = FlippingFlag::FLIP_Y;
		}
		else if(key == KeyCode::KEY_RIGHT)
		{
			if(m_veloc < 3)
				m_veloc += m_accel;
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