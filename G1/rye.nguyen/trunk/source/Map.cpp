#include "stdafx.h"

#include "Map.h"

Map::Map()
{

}

Map::~Map()
{
	
}

void Map::Init(float scale)
{
	m_tile_map = new Image("image//tileset.png");
	m_tile_map->loadImage();
	m_scale = 1.0f;
	//m_scale = scale;
	//m_tile_map->scale(m_scale);

	m_tile_map_width = m_tile_map->getWidth() / (DEFAULT_TILE_WIDTH * m_scale);
	m_tile_map_height = m_tile_map->getHeight() / (DEFAULT_TILE_HEIGHT * m_scale);

	m_width = 0;
	m_height = 0;
	m_map = NULL;
}

void Map::Release()
{
	m_tile_map->unloadImage();
	SAFE_DEL(m_tile_map);

	ReleaseCurrentMap();
}

void Map::LoadMap(int level)
{
	///////////////////////////////////////////
	//Open file and read map
	char* path = _strdup(MAP_PATH);
	path[8] = CHAR(level);

	FILE* f = fopen(path, "rb");

	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* buff = new char[size];
	fread(buff, sizeof(char), size, f);

	fclose(f);

	SAFE_DEL(path);
	///////////////////////////////////////////

	char* temp = buff;
	while(*temp != ' ')
	{
		m_width *= 10;
		m_width += (INT(*temp));
		temp++;
	}
	temp++;

#if PLATFORM != LINUX
	while(*temp != '\r')
#else
	while(*temp != '\n')
#endif
	{
		m_height *= 10;
		m_height += (INT(*temp));
		temp++;
	}
#if PLATFORM == WINDOWS
	temp += 2;
#else
	temp++;
#endif

	m_map = new int*[m_height];
	for(int i = 0; i < m_height; i++)
		m_map[i] = new int[m_width];



	for(int i = 0; i < m_height; i++)
	{
		for(int j = 0; j < m_width; j++)
		{
			m_map[i][j] = 0;
			while(*temp != ',')
			{
				m_map[i][j] *= 10;
				m_map[i][j] += (INT(*temp));
				temp++;
			}
			temp++;
		}
#if PLATFORM == WINDOWS
		temp += 2;
#else
		temp++;
#endif
	}

	SAFE_DEL_ARR(buff);
}

void Map::ReleaseCurrentMap()
{
	for(int i = 0; i < m_height; i++)
		delete[] m_map[i];
	SAFE_DEL_ARR(m_map);

	m_width = 0;
	m_height = 0;
}

int Map::GetWidth()
{
	return m_width;
}

int Map::GetHeight()
{
	return m_height;
}

float Map::GetScale()
{
	return m_scale;
}

void Map::Render(Graphics* g, int offset, int offset_position)
{
	for(int x = 0; x <= SCREEN_WIDTH / (DEFAULT_TILE_WIDTH * m_scale) + 1; x++)
	{
		for(int y = 0; y < m_height; y++)
		{
			if(m_map[y][x + offset] != 0)
			{
				g->drawRegion	(
									m_tile_map,
									offset_position + x * DEFAULT_TILE_WIDTH * m_scale,
									50 + y * DEFAULT_TILE_HEIGHT * m_scale,
									DEFAULT_TILE_WIDTH * m_scale,
									DEFAULT_TILE_HEIGHT * m_scale,
									((m_map[y][x + offset] - 1) % m_tile_map_width) * DEFAULT_TILE_WIDTH * m_scale,
									((m_map[y][x + offset] - 1) / m_tile_map_width) * DEFAULT_TILE_HEIGHT * m_scale,
									DEFAULT_TILE_WIDTH * m_scale, DEFAULT_TILE_HEIGHT * m_scale, 0
								);
			}

			if(offset > 0 && m_map[y][offset - 1] != 0)
			{ }
				/*g->drawRegion	(
									m_tile_map, 
									offset_position - DEFAULT_TILE_WIDTH * m_scale, 
									50 + y * DEFAULT_TILE_HEIGHT * m_scale,
									((m_map[y][offset - 1] - 1) % m_tile_map_width) * DEFAULT_TILE_WIDTH * m_scale,
									((m_map[y][offset - 1] - 1) / m_tile_map_width) * DEFAULT_TILE_HEIGHT * m_scale,
									DEFAULT_TILE_WIDTH * m_scale, DEFAULT_TILE_HEIGHT * m_scale
								);*/
		}
	}

	// g->drawRegion(m_tile_map, Rect(0, 0, 200, 200), Rect(0, 0, 200, 200));
}