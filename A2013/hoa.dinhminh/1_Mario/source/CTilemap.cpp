#include "stdafx.h"

#include "CTilemap.h"
#include <string.h>
#include <math.h>

CTileMap::CTileMap()
{
	this->m_map_width = 0;
	this->m_map_height = 0;
	this->m_tile_map.m_width = 0;
	this->m_tile_map.m_height = 0;
	this->m_tile_set.m_width = 0;
	this->m_tile_set.m_height = 0;
	//this->m_current_top_left_col = 0;
	//this->m_current_top_left_row = 0;
	this->m_data_map = nullptr;
}

ErrorCode CTileMap::load(char* map_file_path)
{
	FILE* fp = fopen(map_file_path, "r");
	if (fp == NULL)
	{
		return ErrorCode::ERR_CANT_OPEN_FILE;
	}
	else
	{
		char tmp[255];
		// ignore line has content [header]
		fscanf(fp, "%s\n", &tmp);

		// get size of map
		fscanf(fp, "width=%d\n", &this->m_map_width);
		fscanf(fp, "height=%d\n", &this->m_map_height);

		// get size of tile in map
		fscanf(fp, "tilewidth=%d\n", &this->m_tile_map.m_width);
		fscanf(fp, "tileheight=%d\n", &this->m_tile_map.m_height);

		// ignore 2 next lines has content "orientation=orthogonal" and "[tilesets]"
		fscanf(fp, "%s\n", &tmp);
		fscanf(fp, "%s\n", &tmp);

		// get info string about tileset source, size of tile in tileset, current t-l tile....
		char info[256];
		fscanf(fp, "tileset=%s\n", &info);
		parseInfo(info);

		// ignore 3 next lines
		fscanf(fp, "%s\n", &tmp);
		fscanf(fp, "%s\n", &tmp);
		fscanf(fp, "%s\n", &tmp);

		// allocate m_data and get map data
		int i, j;
		this->m_data_map = new int*[this->m_map_height];
		for (i = 0; i < m_map_height; i++)
		{
			this->m_data_map[i] = new int[this->m_map_width];
		}

		// get data
		for (i = 0; i < this->m_map_height; i++)
		{
			for (j = 0; j < this->m_map_width; j++)
			{
				int tmp_value;
				fscanf(fp, "%d,", &tmp_value);
				m_data_map[i][j] = tmp_value;
			}
		}

		this->m_tile_set_img = new Image(this->m_tile_set_source);
		return this->m_tile_set_img->loadImage();
	}
	return ErrorCode::ERR_NO_ERROR;
}
void CTileMap::drawTile(Graphics* g, int index_of_tile, int x_map, int y_map)
{
	if (index_of_tile != 0)
	{
		// calculate position of tile in map
		int row = index_of_tile / 64;
		int col = index_of_tile % 64 - 1;

		Rect rect_tileset;
		Rect rect_map;

		rect_tileset.x = col * this->m_tile_set.m_width;
		rect_tileset.y = row * this->m_tile_set.m_height;
		rect_tileset.width = this->m_tile_set.m_width;
		rect_tileset.height = this->m_tile_set.m_height;

		rect_map.x = y_map * this->m_tile_map.m_width;
		rect_map.y = x_map * this->m_tile_map.m_height;
		rect_map.width = this->m_tile_map.m_width;
		rect_map.height = this->m_tile_map.m_height;

		g->drawRegion(this->m_tile_set_img, rect_map, rect_tileset);
	}
}

void CTileMap::drawMap(Graphics*g)
{
	for (int i = 0; i < this->m_map_height; i++)
	{
		for (int j = 0; j < this->m_map_width; j++)
		{
			drawTile(g, this->m_data_map[i][j], i, j);
		}
	}
}

/*
	string info with pattern %s,%d,%d,%d,%d , tilesource, tileset_W, tileset_H, top_left_row, top_left_col
*/
void CTileMap::parseInfo(char* info)
{
	int comma1, comma2, comma3, comma4;
	comma1 = findFirstChar(info, ',');
	comma2 = findFirstChar(info, ',', comma1 + 1);
	comma3 = findFirstChar(info, ',', comma2 + 1);
	comma4 = findFirstChar(info, ',', comma3 + 1);

	strcpy(this->m_tile_set_source,subStr(info, 0, comma1));
	this->m_tile_set.m_width = toInt(subStr(info, comma1 + 1, comma2));
	this->m_tile_set.m_height = toInt(subStr(info, comma2 + 1, comma3));
	//this->m_current_top_left_row = toInt(subStr(info, comma3 + 1, comma4));
	//this->m_current_top_left_col = toInt(subStr(info, comma4 + 1, strlen(info)));
}

char* CTileMap::subStr(char* src, int startIndex, int endIndex)
{
	int length = endIndex - startIndex;
	if (length <= 0)
		return nullptr;

	char* result = new char[length + 1];
	for (int i = 0; i < length; i++)
	{
		result[i] = src[startIndex++];
	}
	result[length] = '\0';
	return result;
}

int CTileMap::findFirstChar(char* src, char ch, int startIndex)
{
	int i;
	for (i = startIndex; i < strlen(src); i++)
	{
		if (src[i] == ch)
		{
			return i;
		}
	}
	return -1;
}

bool CTileMap::isNumber(char* str)
{
	for (int i = 0; i < strlen(str); i++)
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return false;
		}
	}
	return true;
}

int CTileMap::toInt(char* str)
{
	int sum = 0;
	if (isNumber(str))
	{
		for (int i = 0; i < strlen(str); i++)
		{
			int value = str[i] - '0';
			sum += (value * pow(10, strlen(str) - (i + 1)));
		}
		return sum;
	}
	return -1;
}