#pragma once

//////////////////////////////////////////////////////
//Coder: Rye
//Purpose: Load map (prototype)
using namespace stdio_fw;
class Map
{
private:
	char		m_mapPath[256];

	Image*		m_tileSet;
	int			m_tileWidth;
	int			m_tileHeight;

	int**		m_map;
	int			m_mapWidth;
	int			m_mapHeight;
public:
	Map(const char* path);
	~Map();

	void		changeMap(const char* path){}

	ErrorCode			loadMap(){}
	void				unloadMap(){}

	uint		getWidth(){}
	uint		getHeight(){}

	void		drawMap(Graphics* g){}
};