#pragma once

#include "STDIO_FW\Video\Image.h"
using namespace stdio_fw;

#include <list>

/////////////////////////////////////////////
//DATA TYPE DEFINITION
typedef std::list<Image*>			ImageList;
typedef std::list<Image*>::iterator	ImageListIterator;

/////////////////////////////////////////////
//STRUCT
struct Vector2D
{
	int x;
	int y;

	Vector2D(int _x = 0, int _y = 0)
	{
		x = _x;
		y = _y;
	}
	~Vector2D(){}
};

//struct Rect
//{
//	int x;
//	int y;
//	int width;
//	int height;
//
//	Rect(int _x = 0, int _y = 0, int _width = 0, int _height = 0)
//	{
//		x = _x;
//		y = _y;
//		width = _width;
//		height = _height;
//	}
//	~Rect(){}
//};

/////////////////////////////////////////////
//ENUM
enum MoveType
{
	MOVE_UNKNOWN = -1,
	MOVE_NORMAL,
	MOVE_RANDOM,
	MOVE_PLAYER_CONTROL,
	MOVE_COUNT
};

enum EntityType
{
	ENT_UNKNOWN = -1,
	ENT_MUSHROOM,
	ENT_PLAYER,
	ENT_COUNT
};

enum ComponentType
{
	COM_UNKNOWN = -1,
	COM_TRANSFORM,
	COM_MOVEMENT,
	COM_RENDERER,
	COM_ANIMATION,
	COM_LABEL,
	COM_COUNT
};

enum AnimationType
{
	ANM_UNKNOWN = -1,
	ANM_FRAME_IN_SEPARATE_FILE,
	ANM_FRAME_IN_SPRTESHET,
	ANM_COUNT
};