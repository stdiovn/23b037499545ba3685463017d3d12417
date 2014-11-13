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
	int		m_tile_map_width;
	int		m_tile_map_height;

	float	m_scale;
public:
	Map();
	~Map();

	void	Init(float scale = 1.0f);
	void	Release();

	void	LoadMap(int level);
	void	ReleaseCurrentMap();

	int		GetWidth();
	int		GetHeight();

	float	GetScale();

	void	Render(Graphics* g, int offset, int offset_position);
};