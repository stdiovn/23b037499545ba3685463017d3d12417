#ifndef __GAME_H__
#define __GAME_H__
#include "MapManager.h"
#include "Sun.h"
#include "SuperMan.h"
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
protected:
			CMapManager*m_mapManager;
			CSun*		m_sun;
			CSuperMan*	m_superMan;
			Image*		m_congtratulation, *m_gameOver;
};

#endif