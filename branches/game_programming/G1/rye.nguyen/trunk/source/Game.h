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
	int					m_count_of_brick;
	int					m_brick_active_left;

	Image*				m_background;
	Image*				m_game_over;
	Image*				m_win;

	bool				m_is_game_over;
	bool				m_is_win;
	int					m_lives;
	bool				m_is_active;
public:
	Game();
	virtual				~Game();

	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g);
	virtual void		Exit();

	virtual bool		IsExit();
	void				Reset();
};