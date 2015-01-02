#pragma once

////////////////////////////////////////////////////////////
//Coder: Rye
#include "BaseObject.h"

using namespace stdio_fw;
class Mario : public BaseObject
{
private:
	int					m_lives;
	MarioState			m_state;
	bool				m_canShoot;

	int			m_veloc;
	int			m_accel;
	bool		m_isBoost;

	void		stand();
	void		run(KeyCode key);
	void		jump();
	void		sit();
public:
	Mario(Image* spritesheet, std::vector<Frame>* frameList)
		: BaseObject(spritesheet, frameList){
		m_lives = 1;
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
		
		m_veloc = 0;
		m_accel = 1;
		m_isBoost = false;
	}
	~Mario(){}

	void		update();
	void		draw(Graphics* g);
};