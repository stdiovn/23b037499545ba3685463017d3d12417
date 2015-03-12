#pragma once
#include "Objects.h"
using namespace stdio_fw;


class Game : public Application
{
	Ball ball;
	Bar bar;
	vector<Brick> ArrBrick;
public:

	Game();
	virtual ~Game();

	virtual ErrorCode	init(int screenW, int screenH, const char* title);
	virtual void		update(float deltaTime);

	virtual void		render(Graphics* g);
	virtual void		onKeyProc(KeyCode key, KeyState state);
	virtual void		exit();
};