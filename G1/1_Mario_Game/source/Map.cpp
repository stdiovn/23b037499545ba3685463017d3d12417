#include "stdafx.h"

#include "ResourcesManager.h"
#include "Map.h"

Map::Map(const char* path)
{
	strcpy_s(m_mapPath, path);
}

Map::~Map()
{
	unloadMap();
}

void Map::unloadMap()
{
	for (int i = 0; i < m_mapHeight; i++)
		delete m_map[i];
	SAFE_DEL_ARR(m_map);
}

#pragma region loadMap
//int getNumber(char *s)
//{
//	char temp[1024] = { 0 };
//	int n = 0;
//	for (int i = 0; i < strlen(s); i++)
//	{
//		if (s[i] >= '0' && s[i] <= '9')
//		{
//			temp[n++] = s[i];
//		}
//	}
//	return atoi(temp);
//}

void setEmpty(char *s, int size)
{
	for (int i = 0; i < size; i++)
		s[i] = 0;
}

ErrorCode Map::loadMap()
{
	FILE *f = fopen(m_mapPath, "rb");

	if (f != NULL)
	{
		char s[1024];

		while (!feof(f))
		{
			setEmpty(s, 1024);
			fgets(s, 1024, f);

			if (strstr(s, "tilewidth=") != NULL)
			{
				m_tileWidth = getNumber(s);
			}
			else if (strstr(s, "tileheight=") != NULL)
			{
				m_tileHeight = getNumber(s);
			}
			else if (strstr(s, "height=") != NULL)
			{
				m_mapHeight = getNumber(s);
			}
			else if (strstr(s, "width=") != NULL)
			{
				m_mapWidth = getNumber(s);
			}
			else if (strstr(s, "data=") != NULL)
			{
				m_map = new int*[m_mapHeight];
				for (int i = 0; i < m_mapHeight; i++)
					m_map[i] = new int[m_mapWidth];

				int row = 0;
				int column = 0;

				while (!feof(f))
				{
					setEmpty(s, 1024);
					fgets(s, 1024, f);

					if (row == m_mapHeight)
						break;

					char temp[100] = { 0 };
					int m = 0;

					int size = strlen(s);
					for (int i = 0; i < size; i++)
					{
						if (s[i] != ',')
							temp[m++] = s[i];
						else
						{
							m_map[row][column] = atoi(temp);

							if (++column >= m_mapWidth)
							{
								column = 0;
							}

							m = 0;
							setEmpty(temp, 100);
						}
					}

					row++;
				}
			}
			else if (strstr(s, "# ") != NULL)
			{
				setEmpty(s, 1024);

				InformationObject object;

				fgets(s, 1024, f);
				if (strstr(s, "type=") != NULL)
				{
					object.m_id = getNumber(s);
				}

				setEmpty(s, 1024);
				fgets(s, 1024, f);

				char temp[100] = { 0 };
				int m = 0;

				int id = 0;

				for (int i = strlen("location="); i < strlen(s); i++)
				{
					if (s[i] >= '0' && s[i] <= '9')
					{
						temp[m++] += s[i];
					}
					else if (s[i] == ',' || s[i] == '\n')
					{
						switch (id)
						{
						case 0:
							object.m_llocation.x = getNumber(temp) * m_tileWidth;
							break;
						case 1:
							object.m_llocation.y = getNumber(temp) * m_tileHeight;
							break;
						case 2:
							object.m_llocation.width = getNumber(temp) * m_tileWidth;
							break;
						case 3:
							object.m_llocation.height = getNumber(temp) * m_tileHeight;
							break;
						}

						id++;
						m = 0;
						setEmpty(temp, 100);
					}
				}

				m_informationObjects.push_back(object);
			}
		}
		fclose(f);

		m_tileSet = ResourcesManager::getInstance()->getResource(SpriteSheet::SHEET_TILESET);
		//m_tileSet->loadImage();

		return ErrorCode::ERR_NO_ERROR;
	}

	return ErrorCode::ERR_CANT_OPEN_FILE;
}

#pragma endregion


void Map::setCamera(int vpx, int vpy)
{
	m_vpx = vpx;
	m_vpy = vpy;

	//if (m_vpx - SCREEN_WIDTH / 2 < 0) m_vpx = 0;
}

void Map::drawMap(Graphics *g)
{
	Mat3 matrix;
	matrix.setTranslation(m_vpx, m_vpy);

	Vec3 vector(0, 0, 1);
	for (int i = 0; i < m_mapHeight; i++)
	{
		for (int j = 0; j < m_mapWidth; j++)
		{
			if (m_map[i][j] != 0)
			{
				float src_x = (m_map[i][j] % (m_tileSet->getWidth() / m_tileWidth) - 1) * m_tileWidth;
				float src_y = m_map[i][j] / (m_tileSet->getWidth() / m_tileWidth) * m_tileHeight;

				vector.x = j * m_tileWidth;
				vector.y = i * m_tileHeight;
				vector.z = 1;

				vector = vector *  matrix;
				g->drawRegion(m_tileSet, Rect(vector.x, vector.y, m_tileWidth, m_tileHeight), Rect(src_x, src_y, m_tileWidth, m_tileHeight), FLIP_NONE);
			}
		}
	}
}

