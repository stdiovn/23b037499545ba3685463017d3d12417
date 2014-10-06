#pragma once

#include "Ball.h"
#include "Bar.h"
#include "Brick.h"

#include "support.h"

using namespace stdio_fw;

class Game : public Application
{
private:
	Ball*				m_ball;
	Bar*				m_bar;
	Brick**				m_brick;

	Image*				m_background;
public:
	Game();
	virtual				~Game();

	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g);
	virtual void		Exit();

	virtual bool		IsExit();
};