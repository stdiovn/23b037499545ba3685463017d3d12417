#pragma once
#include "Object.h"
#include "StaticObject.h"
#include "MoveableObject.h"

using namespace stdio_fw;
class Game : public Application
{
protected:
	StaticObject *mBackground;
	MoveableObject *mBrick;
	MoveableObject *mBall;
public:
	Game();
	virtual ~Game();

	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g);
	virtual void		Exit();
};