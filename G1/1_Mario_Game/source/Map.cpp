#include "stdafx.h"

#include "Map.h"

Map::Map(const char* path)
{
	strcpy_s(m_mapPath, path);
}

Map::~Map()
{
	unloadMap();
}

