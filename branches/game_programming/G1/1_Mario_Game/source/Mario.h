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

	void		stand();
	void		run(KeyCode key);
	void		jump();
	void		sit();
public:
	Mario(Image* spritesheet, std::vector<Frame>* frameList)
		: BaseObject(spritesheet, frameList){
		m_lives = 1;
		m_state = MarioState::MS_STANDING;
		m_position = Vec2(30, 224 - 64);
	}
	~Mario(){}

	void		update();
	void		draw(Graphics* g);
};