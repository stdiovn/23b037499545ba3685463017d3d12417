#pragma once
#include "Rect.h"
#include "Square.h"
using namespace stdio_fw;
class Game : public Application
{
private:
	
	Rect* R;
	Square* S;
	Image* GameOverImage;
	unsigned int m_SqrColor;
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