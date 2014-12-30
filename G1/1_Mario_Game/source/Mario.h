#pragma once

////////////////////////////////////////////////////////////
//Coder: Rye
#include "BaseObject.h"

using namespace stdio_fw;
class Mario : public BaseObject
{
private:
	int			m_lives;

	void		stand();
	void		run(KeyCode key);
	void		jump();
	void		sit();
public:
	Mario(Image* spritesheet, std::vector<Frame>* frameList)
		: BaseObject(spritesheet, frameList){}
	~Mario(){}

	void		update();
	void		draw(Graphics* g);
};