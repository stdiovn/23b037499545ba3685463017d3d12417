#pragma once
#include "Object.h"
#include "StaticObject.h"
#include "MoveableObject.h"
#include "BrickVector.h"

using namespace stdio_fw;

class Game : public Application
{
protected:
	StaticObject *m_Background;
	MoveableObject *m_Ball;
	MoveableObject *m_Bar;
	BrickVector *m_BrickVector;
public:
	Game();
	virtual ~Game();

	virtual ErrorCode	init(int screenW, int screenH, const char* title);
	virtual void		update(float deltaTime);

	virtual void		render(Graphics* g);
	virtual void		onKeyProc(KeyCode key, KeyState state);
	virtual void		exit();
};