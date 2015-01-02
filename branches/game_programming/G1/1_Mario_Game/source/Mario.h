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

	int			m_accel;
	bool		m_isBoost;

	void		stand();
	void		run(KeyCode key);
	void		jump();
	void		sit();
public:
	Mario(Image* spritesheet, std::vector<Frame>* frameList);
	~Mario();

	void		update();
	void		draw(Graphics* g);
};