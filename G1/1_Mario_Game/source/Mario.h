#pragma once

#include "BaseObject.h"

using namespace stdio_fw;
class Mario : public BaseObject
{
private:
	Image*		m_mario;
	Frame*		m_marioFrameList;

	void		stand();
	void		run();
	void		jump();
	void		sit();
public:
	Mario(Image* image, Frame* frameList);
	~Mario();

	void		update();
	void		draw(Graphics* g);
};