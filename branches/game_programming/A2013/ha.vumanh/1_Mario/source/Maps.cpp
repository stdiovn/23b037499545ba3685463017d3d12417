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
	matrix_data = new int*[tileRows];
	for (int i = 0; i <= tileRows; i++)
	{
		matrix_data[i] = new int[tileColumns];
	}
}

void Maps::openMapTiles(const char* filepart)
{
	char temp[255]; //save strash when read file
	mapsInfo = fopen(filepart, "r");

	//ignore line 1
	fscanf(mapsInfo, "%s\n", &temp);

	fscanf(mapsInfo, "width=%d\n" , &tileColumns);
	fscanf(mapsInfo, "height=%d\n", &tileRows);
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
		fscanf(mapsInfo, "%d", &matrix_data[i][0]);
		for (int j = 1; j < tileColumns; j++)
			fscanf(mapsInfo, ",%d", &matrix_data[i][j]);
		fscanf(mapsInfo, ",\n", &temp);
	}
	fclose(mapsInfo);
}

void Maps::reModifiedPositionTileDraw(int value)
{
	int a = value % 64; // 64 is number of tile in one rows on tileset.
	int b = value / 64;
	positionDraw_X = tileWidth * a;
	positionDraw_Y = tileHeight * b;
}

void Maps::modifiedSth(int ScreenW,int ScreenH)
{
	currentColumnsDraw = 0;
	prefixPosition = 0;
	movementSpeed = 4;
	ingame_tileWidth = ingame_tileHeight = ScreenH / 16; // 16 is number of tile in one columns follow the "tiled".
	columnsOnScene = (ScreenW / ingame_tileWidth) + 2; // load 2 more columns foward
	
}

void Maps::goRight()
{
	if ((currentColumnsDraw + columnsOnScene) < tileColumns)
	{
		if (prefixPosition < ingame_tileWidth)
			prefixPosition += movementSpeed;
		else
		{
			currentColumnsDraw++;
			prefixPosition -= ingame_tileWidth;
		}
	}
}

void Maps::goLeft()
{
	if (currentColumnsDraw > 0)
	{
		if (prefixPosition >= 0 && prefixPosition < ingame_tileWidth)
			prefixPosition -= movementSpeed;
		else
		{
			currentColumnsDraw--;
			prefixPosition = ingame_tileWidth - movementSpeed; // follow on prefixPosition -= movementSpeed
		}
	}
	else
	{
		if(prefixPosition > 0)
			prefixPosition -= movementSpeed;
	}
}

void Maps::render(Graphics* g)
{
	int drawTileX, drawTileY;
	for (int i = 0; i < tileRows; i++)
	{
		drawTileY = ingame_tileHeight * i;
		int k = currentColumnsDraw;
		for (int j = 0; j < columnsOnScene; j++)
		{
			drawTileX = ingame_tileWidth * j;		
			if (matrix_data[i][k] > 0)
			{
				reModifiedPositionTileDraw(matrix_data[i][k] - 1);
				g->drawRegion(tileSet, Rect((drawTileX - prefixPosition), drawTileY, ingame_tileWidth, ingame_tileHeight), Rect(positionDraw_X, positionDraw_Y, tileWidth, tileHeight));				
			}
			k++;
		}
	}
}
Maps::~Maps()
{
	for (int i = tileRows; i >= 0; i--)
		delete matrix_data[i];
	delete matrix_data;

}