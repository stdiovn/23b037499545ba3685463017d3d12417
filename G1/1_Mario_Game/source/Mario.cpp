#include "stdafx.h"

#include "Mario.h"

void Mario::update()
{
	float currentTime = GetTickCount();
	m_elapseFrameTime = currentTime - m_lastTime;
	if(m_elapseFrameTime > 1000 / FRAME_TIME)
		m_lastTime = currentTime;

	if(GetAsyncKeyState(VK_LEFT))
	{
		run(KeyCode::KEY_LEFT);
	}
	else if(GetAsyncKeyState(VK_RIGHT))
	{
		run(KeyCode::KEY_RIGHT);
	}
	else
		stand();
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

	m_currentFrame = 0;
}

void Mario::run(KeyCode key)
{
	if(m_state != MarioState::MS_RUNNING)
		m_state = MarioState::MS_RUNNING;

	if(m_elapseFrameTime > 1000.0f / FRAME_TIME)
	{
		m_elapseFrameTime = 0;
		if(m_currentFrame > 2)
			m_currentFrame = 0;
		m_currentFrame++;
	}
	
	if(key == KeyCode::KEY_LEFT)
	{
		m_position.x -= 2;
		if(m_flipping == FlippingFlag::FLIP_NONE)
			m_flipping = FlippingFlag::FLIP_X;
	}
	else if(key == KeyCode::KEY_RIGHT)
	{
		m_position.x += 2;
		if(m_flipping == FlippingFlag::FLIP_X)
			m_flipping = FlippingFlag::FLIP_NONE;
	}
}

void Mario::jump()
{

}

void Mario::sit()
{

}