#include "stdafx.h"
#include "Maps.h"
#include <iostream>

Maps::Maps()
{

}

Maps::Maps(const char* tileSet_img)
{
	tileSet = new Image(tileSet_img);
	tileSet->loadImage();
}

void Maps::createMatrix(int rows, int columns)
{
	matrix = new int*[tileRows];
	for (int i = 0; i <= tileRows; i++)
	{
		matrix[i] = new int[tileColumns];
	}
}

void Maps::openMapTiles(const char* filepart)
{
	char temp[255];
	mapsInfo = fopen(filepart, "r");

	//ignore line 1
	fscanf(mapsInfo, "%s\n", &temp);

	fscanf(mapsInfo, "width=%d\n" , &tileRows);
	fscanf(mapsInfo, "height=%d\n", &tileColumns);
	fscanf(mapsInfo, "tilewidth=%d\n", &ingame_tileWidth);
	fscanf(mapsInfo, "tileheight=%d\n", &ingame_tileHeight);
	
	//ignore some trash character
	fscanf(mapsInfo, "%s\n", &temp);
	fscanf(mapsInfo, "%s\n", &temp);

	fscanf(mapsInfo, "tileset=tileset.png,%d,%d,%d,%d\n", &tileWidth, &tileHeight, &positionDraw_X, &positionDraw_Y);

	//ignore some trash character
	fscanf(mapsInfo, "%s\n", &temp);
	fscanf(mapsInfo, "%s\n", &temp);
	fscanf(mapsInfo, "%s\n", &temp);
	fscanf(mapsInfo, "%s\n", &temp);
	fscanf(mapsInfo, "%s\n", &temp);

	createMatrix(tileRows, tileColumns);
	for (int i = 0; i < tileRows; i++)
	{
		fscanf(mapsInfo, "%d", &matrix[i][0]);
		for (int j = 1; j < tileColumns; j++)
			fscanf(mapsInfo, ",%d", &matrix[i][j]);
		fscanf(mapsInfo, ",\n", &temp);
	}
	fclose(mapsInfo);
}

void Maps::getPositionTileDraw(int value)
{
	int a = value % 64;
	int b = value / 64;
	positionDraw_X = tileWidth * a;
	positionDraw_Y = tileHeight * b;
}

void Maps::render(Graphics* g)
{
	for (int i = 0; i < tileRows; i++)
	{
		int drawTileY = tileHeight * i;
		for (int j = 0; j < tileColumns; j++)
		{
			int drawTileX = tileWidth * j;
			if (matrix[i][j] > 0)
			{
				getPositionTileDraw(matrix[i][j] - 1);
				g->drawRegion(tileSet, Rect(positionDraw_X, positionDraw_Y, tileWidth, tileHeight), Rect(drawTileX, drawTileY, ingame_tileWidth, ingame_tileHeight));
			}
		}
	}
}
Maps::~Maps()
{
	
}