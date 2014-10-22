#pragma once
#include "Boomerang.h"
#include "Turtle.h"
#include "Brick.h"
using namespace stdio_fw;
#define Row 3
#define Column 13
class Game : public Application
{
private:
	Boomerang* Bmr;
	Turtle* Tur;
	Brick* Brk[Row][Column];
	Image* m_GameOverImage;
	Image* m_Background;
	int m_Map;
	int m_CountIsAlive;
	FILE* f;
public:
	Game();
	virtual ~Game();
	virtual void		LimitFPS(int Limit, float DeltaTime);
	virtual unsigned int ColorRandom(int Red, int Green, int Blue, int Alpha);
	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g);
	virtual void		Exit();
};