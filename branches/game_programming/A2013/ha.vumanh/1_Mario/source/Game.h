#pragma once
#include "Maps.h"
using namespace stdio_fw;

class Game : public Application
{
public:
	Maps* map_testing;
	Game();
	virtual ~Game();

	virtual ErrorCode	init(int screenW, int screenH, const char* title);
	virtual void		update(float deltaTime);

	virtual void		render(Graphics* g);
	virtual void		exit();

	virtual void		onKeyProc(KeyCode key, KeyState state);
};