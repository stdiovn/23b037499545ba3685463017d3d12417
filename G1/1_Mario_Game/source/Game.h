#pragma once
#include "Map.h"
#include "Mario.h"

using namespace stdio_fw;
class Game : public Application
{
private:
	//Font*				m_font;
	GameState			m_state;

	Map*				m_map;
	Mario*				m_mario;

public:
	Game();
	virtual ~Game();

	virtual ErrorCode	init(int screenW, int screenH, const char* title);
	virtual void		update(float deltaTime);

	virtual void		render(Graphics* g);
	virtual void		exit();

	virtual void		onKeyProc(KeyCode key, KeyState state);
};