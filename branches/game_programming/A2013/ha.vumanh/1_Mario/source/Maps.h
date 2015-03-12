#include "stdafx.h"
using namespace stdio_fw;

class Maps
{
private:
	FILE* mapsInfo;
	Image* tileMaps_img;
	Image* tileSet;
	int** matrix_data;
	int** matrix_scene;
	int tileColumns,
		tileRows,
		tileHeight,
		tileWidth,
		ingame_tileWidth,
		ingame_tileHeight,
		positionDraw_X,
		positionDraw_Y,
		columnsOnScene,
		currentColumnsDraw,
		prefixPosition;
public:
	Maps();
	Maps(const char*);
	void openMapTiles(const char*);
	void createMatrix(int, int);
	void modifiedSth(int, int);
	void reModifiedPositionTileDraw(int);
	void reCopyData(int);
	void goRight();
	void goLeft();
	void render(Graphics*);
	~Maps();
};