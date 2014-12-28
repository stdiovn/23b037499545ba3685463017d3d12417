#pragma once
#include <list>
#include"EntityManager.h"
using namespace stdio_fw;
#define Row 3
#define Column 13
#include "RenderSystem.h"
#include "MovementSystem.h"
#include "AnimationSystem.h"

class Factory;
class EntityManager;
class Game : public Application
{
private:
	Factory* m_Factory;
	RenderSystem* m_Render;
	MovementSystem* m_Move;
	AnimationSystem* m_Animation;

public:
	Game();
	virtual ~Game();
	virtual void		LimitFPS(int Limit, float DeltaTime);
	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g);
	virtual void		Exit();
};