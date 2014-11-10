#pragma once

#include "STDIO_FW\Core\Application.h"
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
using namespace stdio_fw;

#include "Map.h"

class Game : public Application
{
private:
	Map*				m_map;
	int					m_offset_position;
	int					m_map_offset;
public:
	Game();
	virtual				~Game();

	virtual ErrorCode	Init(int screenW, int screenH, const char* title);
	virtual void		Update(float deltaTime);

	virtual void		Render(Graphics* g);
	virtual void		Exit();
};