#pragma once

using namespace stdio_fw;
class Mushroom : public BaseObject
{
private:
	Image*		m_enemies;
	Frame*		m_enemyFrameList;
public:
	Mushroom(Image* image, Frame* frameList);
	~Mushroom();

	void		update();
	void		render(Graphics* g);
};