#ifndef __GAME_H__
#define __GAME_H__
#include "Ball.h"
#include "Bar.h"
using namespace stdio_fw;
class Game : public Application
{
public:
	Game();
	virtual ~Game();

	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);
	virtual void		Render(Graphics* g);
	virtual void		Exit();
			void		UpdateInputHandle();
protected:
	CBall*				m_miniBall;
	CMoveableObject*	m_miniBar;
	CMapmanager*		m_map;
};

#endif