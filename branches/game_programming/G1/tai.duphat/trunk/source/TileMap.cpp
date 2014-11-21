#include "stdafx.h"
#include "TileMap.h"
#include <stdlib.h>  


int getNumber(char *s)
{
	char temp[10] = { 0 };
	int n = 0;
	for (int i = 0; i < strlen(s); i++)
	{
		if (s[i] >= '0' && s[i] <= '9')
		{
			temp[n++] = s[i];
		}
	}
	return atoi(temp);
}
void setEmpty(char *s, int size)
{
	for (int i = 0; i < size; i++)
		s[i] = 0;
}
TileMap::TileMap(char  *Path)
{
	FILE *f = fopen(Path, "rb");

	if (f != NULL)
	{
		char s[1024] = { 0 };

		while (!feof(f))
		{
			fgets(s, 1024, f);

			if (strstr(s, "tilewidth=") != NULL)
			{
				m_TileWidth = getNumber(s);
			}
			else if (strstr(s, "tileheight=") != NULL)
			{
				m_TileHeight = getNumber(s);
			}
			else if (strstr(s, "height=") != NULL)
			{
				m_Height = getNumber(s);
			}
			else if (strstr(s, "width=") != NULL)
			{
				m_Width = getNumber(s);
			}
			else if (strstr(s, "tileset=") != NULL)
			{
				int n = 0;
				for (char *i = strstr(s, "tileset=") + strlen("tileset="); *i != ','; i++)
				{
					m_TileSet[n++] = *i;
				}
			}
			else if (strstr(s, "data=") != NULL)
			{
				m_Array = new char[m_Width * m_Height];
				int n = 0;

				while (!feof(f))
				{
					setEmpty(s, 1024);
					fgets(s, 1024, f);
					
					char temp[100] = { 0 };
					int m = 0;

					int size = strlen(s);
					for (int i = 0; i < size; i++)
					{
						if (s[i] != ',')
							temp[m++] = s[i];
						else
						{
							m_Array[n++] = atoi(temp);
							m = 0;
							setEmpty(temp, 100);
						}
					}
				}
			}
		}
		fclose(f);

		m_Image = new Image(m_TileSet);
		m_Image->loadImage();

		m_SpritePerRow = m_Image->getWidth() / m_TileWidth;
	}
}


void TileMap::Render(Graphics *g)
{
	for (int i = 0; i < m_Width * m_Height; i++)
	{
		if (m_Array[i] != 0)
		{
			int scr_x = (m_Array[i] % m_SpritePerRow - 1) * m_TileWidth;
			int scr_y = (m_Array[i] / m_SpritePerRow) * m_TileHeight;

			int x = (i % m_Width) * m_TileWidth;
			int y = (i / m_Width) * m_TileHeight;
			g->drawRegion(m_Image, x, y, scr_x, scr_y, m_TileWidth, m_TileHeight);
		}
	}
}
TileMap::~TileMap()
{
	delete m_Array;
}