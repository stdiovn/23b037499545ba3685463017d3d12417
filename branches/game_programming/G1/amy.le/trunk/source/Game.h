#pragma once
//#include "Block.h"
//#include "RectControl.h"

using namespace stdio_fw;
class Game : public Application
{
private:
	int m_SqrSpeedX;
	int m_SqrSpeedY;
	int m_RectSpeedX;
	int m_SqrX;
	int m_SqrY;
	int m_RectX;
	int m_RectY;
	unsigned int m_SqrColor;
public:
	Game();
	virtual ~Game();
	virtual void		LimitFPS(int Limit, float DeltaTime);
	virtual unsigned int ColorRandom(int Red, int Green, int Blue, int Alpha);
	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g/*, Block* b, RectControl* r*/);
	virtual void		Exit();
};