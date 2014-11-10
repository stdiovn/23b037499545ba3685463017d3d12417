#include "stdafx.h"

#include "Map.h"

Map::Map()
{

}

Map::~Map()
{

}

void Map::Init()
{
	m_tile_map = new Image("image//tileset.png");
	m_tile_map->loadImage();

	m_tile_width = m_tile_map->getWidth() / 20;
	m_tile_height = m_tile_map->getHeight() / 20;

	m_width = 0;
	m_height = 0;
	m_map = NULL;
}

void Map::Release()
{
	m_tile_map->unloadImage();
	SAFE_DEL(m_tile_map);
}

void Map::LoadMap(int level)
{
	char* path = _strdup(MAP_PATH);
	path[8] = level + 48;

	FILE* f = fopen(path, "rb");

	fseek(f, 0, SEEK_END);
	int size = ftell(f);
	fseek(f, 0, SEEK_SET);

	char* buff = new char[size];
	fread(buff, sizeof(char), size, f);

	fclose(f);

	SAFE_DEL(path);

	char* temp = buff;
	while(*temp != '\r')
	{
		m_width *= 10;
		m_width += (*temp - 48);

		temp++;
	}
	temp += 2;

	while(*temp != '\r')
	{
		m_height *= 10;
		m_height += (*temp - 48);

		temp++;
	}
	temp += 2;

	m_map = new int*[m_height];
	for(int i = 0; i < m_height; i++)
	{
		m_map[i] = new int[m_width];
	}

	for(int i = 0; i < m_height; i++)
	{
		for(int j = 0; j < m_width; j++)
		{
			m_map[i][j] = 0;
			while(*temp != ',')
			{
				m_map[i][j] *= 10;
				m_map[i][j] += (*temp - 48);
				temp++;
			}

			temp++;
		}

		temp += 2;
	}

	SAFE_DEL_ARR(buff);
}

void Map::ReleaseCurrentMap()
{
	for(int i = 0; i < m_height; i++)
		SAFE_DEL_ARR(m_map[i]);

	m_map = NULL;
	m_width = 0;
	m_height = 0;
}

void Map::Render(Graphics* g, int offset, int offset_position)
{
	/*for(int x = 0; x < 40; x++)
	{
		for(int y = 0; y < 8; y++)
		{
			g->drawRegion(m_tile_map, offset_position + x * 20, 50 + y * 20, ((m_map[y][x + offset] - 1) % m_tile_width) * 20, ((m_map[y][x + offset] - 1) / m_tile_width) * 20, 20, 20);
		}
	}*/
	
	//g->drawRegion(m_tile_map, 0, 0, 0, 0, 240, 60);
	g->drawRegion(m_tile_map, 0, 0, 0, 0, 240, 100);
}