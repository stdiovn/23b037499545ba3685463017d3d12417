#pragma once

//////////////////////////////////////////////////////
//Coder: Rye
//Purpose: Load map (prototype)
#include <list>

using namespace stdio_fw;
class Map
{
private:
	char		m_mapPath[256];

	Image*		m_tileSet;
	uint		m_tileWidth;
	uint		m_tileHeight;

	uint**		m_map;
	uint		m_mapWidth;
	uint		m_mapHeight;

	int			m_vpx;
	int			m_vpy;

	std::list<InformationObject>	m_informationObjects;
public:
	Map(const char* path);
	~Map();

	void		changeMap(const char* path);

	ErrorCode		loadMap();
	void			unloadMap();

	uint		getWidth(){ return m_mapWidth; }
	uint		getHeight(){ return m_mapHeight; }

	std::list<InformationObject>	getInformationObjects(){ return m_informationObjects; }

	void		setCamera(int vpx, int vpy);

	void		drawMap(Graphics* g);
};
//////////////////////////////////////////////////////