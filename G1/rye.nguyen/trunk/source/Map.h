#pragma once

#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
using namespace stdio_fw;

class Map
{
private:
	int**	m_map;
	int		m_width;
	int		m_height;

	Image*	m_tile_map;
	int		m_tile_width;
	int		m_tile_height;
public:
	Map();
	~Map();

	void	Init();
	void	Release();

	void	LoadMap(int level);
	void	ReleaseCurrentMap();

	void	Render(Graphics* g, int offset, int offset_position);
};