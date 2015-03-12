#include "stdafx.h"
using namespace stdio_fw;

class Maps
{
private:
	FILE* mapsInfo;
	Image* tileMaps_img;
	Image* tileSet;
	int** matrix;
	int tileColumns,
		tileRows,
		tileHeight,
		tileWidth,
		ingame_tileWidth,
		ingame_tileHeight,
		positionDraw_X,
		positionDraw_Y;
public:
	Maps();
	Maps(const char*);
	void openMapTiles(const char*);
	void createMatrix(int, int);
	void getPositionTileDraw(int);
	void render(Graphics*);
	~Maps();
};