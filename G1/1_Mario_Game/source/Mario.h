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
		m_lives = 2;
		m_state = MarioState::MS_STANDING;
		m_position = Vec2(30, 224 - 64);
		m_canShoot = false;
		m_isActive = true;

		m_veloc = 0;
		m_accel = 1;
		m_isBoost = false;
	}
	~Mario(){}

	void		update();
	
	void		draw(Graphics* g);
};