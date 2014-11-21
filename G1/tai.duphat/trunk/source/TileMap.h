#ifndef _TileMap_
#define _TileMap_
#include "STDIO_FW\Video\Graphics.h"
#include "STDIO_FW\Video\Image.h"
#include <stdio.h>
#include <string.h>
using namespace stdio_fw;

class TileMap
{
protected:
	char *m_Array;

	int m_Width;
	int m_Height;
	int m_TileWidth;
	int m_TileHeight;

	int m_SpritePerRow;
	Image *m_Image;
	char m_TileSet[100];
public:
	TileMap(char *Path);
	void Render(Graphics *g);
	~TileMap();
};


#endif